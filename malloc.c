#include "libft_malloc.h"

t_zones g_zones = {.tiny = NULL, .small = NULL, .large = NULL};

/**
 * Creates a new block of memory (inside a zone, usable by malloc)
 * @param starting_addr The address where to insert the block inside the zone
 * @param size The size of the memory block (header excluded)
 */
t_block *new_block(void *starting_addr, size_t size)
{
    t_block *block = (t_block *)starting_addr;
    block->size = size;
    block->next = NULL;
    block->prev = NULL;
    block->free = 0;
    return block;
}

/**
 * Creates a new zone of memory
 * @param type The type of the memory zone (TINY or SMALL only)
 * @param size The size of the memory zone
 * @return The new zone
 * @note The zone's header is included in the size
 */
t_zone *new_zone(e_zone_type type, size_t size)
{
    void *ptr;
    size_t tiny_init_pages = 128 * TINY_LIMIT / getpagesize();
    size_t small_init_pages = 128 * SMALL_LIMIT / getpagesize();

    if (type == TINY) {
        size = tiny_init_pages * getpagesize();
        ptr = MMAP(0, size);
    }
    else if (type == SMALL) {
        size = small_init_pages * getpagesize();
        ptr = MMAP(0, size);
    }
    if (ptr == MAP_FAILED)
        return NULL;

    t_zone *zone = (t_zone *)ptr;
    zone->size = size;
    zone->next = NULL;
    zone->blocks = NULL;
    return zone;
}


size_t net_remaining_space(t_zone *zone)
{
    size_t remaining_space;
    t_block *block;
    
    remaining_space = zone->size - sizeof(t_zone);
    block = zone->blocks;
    while (block)
    {
        remaining_space -= block->size + sizeof(t_block);
        block = block->next;
    }
    return remaining_space;
}

static void *get_large_address(size_t size)
{
    t_zone *ptr;

    if (g_zones.large == NULL)
    {
        ptr = MMAP(0, size + sizeof(t_zone));
        if (ptr == MAP_FAILED)
            return NULL;
        g_zones.large = ptr;
    }
    else
    {
        ptr = go_to_last_zone(g_zones.large);
        ptr->next = MMAP(0, size + sizeof(t_zone));
        if (ptr->next == MAP_FAILED)
            return NULL;
        ptr = ptr->next;
    }
    ptr->size = size;
    ptr->next = NULL;
    ptr->blocks = 0;
    return BYT(ptr) + sizeof(t_zone);
}

static t_block *allocate_from_free_block(size_t size, e_zone_type type)
{
    t_zone *zone = type == TINY ? g_zones.tiny : g_zones.small;
    t_block *block;

    while (zone)
    {
        block = zone->blocks;
        while (block)
        {
            if (block->free && block->size >= size)
            {
                block->free = 0;
                // check if we can split the block to take only the needed size
                if (block->size > size + sizeof(t_block))
                {
                    t_block *tmp_next = block->next;
                    block->next = new_block(
                        BYT(block) + sizeof(t_block) + size,
                        block->size - size - sizeof(t_block));
                    block->next->prev = block;
                    block->next->next = tmp_next;
                    block->size = size;
                }
                return block;
            }
            block = block->next;
        }
        zone = zone->next;
    }
    return NULL;
}

static void *get_tiny_address(size_t size)
{
    if (g_zones.tiny == NULL)
    {
        g_zones.tiny = new_zone(TINY, size);
        if (g_zones.tiny == NULL)
            return NULL;
        g_zones.tiny->blocks = new_block(BYT(g_zones.tiny) + sizeof(t_zone), size);
        return BYT(g_zones.tiny->blocks) + sizeof(t_block);
    }
    else
    {
        // try to allocate in a freed block
        t_block *block = allocate_from_free_block(size, TINY);
        if (block)
            return BYT(block) + sizeof(t_block);
        // else, create a new block at the end of the last zone
        t_zone *last_zone = go_to_last_zone(g_zones.tiny);
        t_block *last_block = go_to_last_block(last_zone->blocks);
        if (net_remaining_space(last_zone) >= size + sizeof(t_block))
        {
            last_block->next = new_block(
                BYT(last_block) + sizeof(t_block) + last_block->size, size);
            last_block->next->prev = last_block;
            return BYT(last_block->next) + sizeof(t_block);
        }
        else
        {
            last_zone->next = new_zone(TINY, size);
            if (last_zone->next == NULL)
                return NULL;
            last_zone->next->blocks = new_block(
                BYT(last_zone->next) + sizeof(t_zone), size);
            return BYT(last_zone->next->blocks) + sizeof(t_block);
        }
    }
}

static void *get_small_address(size_t size)
{
    if (g_zones.small == NULL)
    {
        g_zones.small = new_zone(SMALL, size);
        if (g_zones.small == NULL)
            return NULL;
        g_zones.small->blocks = new_block(BYT(g_zones.small) + sizeof(t_zone), size);
        return BYT(g_zones.small->blocks) + sizeof(t_block);
    }
    else
    {
        // try to allocate in a freed block
        t_block *block = allocate_from_free_block(size, SMALL);
        if (block)
            return BYT(block) + sizeof(t_block);
        // else, create a new block at the end of the last zone
        t_zone *last_zone = go_to_last_zone(g_zones.small);
        t_block *last_block = go_to_last_block(last_zone->blocks);
        if (net_remaining_space(last_zone) >= size + sizeof(t_block))
        {
            last_block->next = new_block(
                BYT(last_block) + sizeof(t_block) + last_block->size, size);
            last_block->next->prev = last_block;
            return BYT(last_block->next) + sizeof(t_block);
        }
        else
        {
            last_zone->next = new_zone(SMALL, size);
            if (last_zone->next == NULL)
                return NULL;
            last_zone->next->blocks = new_block(
                BYT(last_zone->next) + sizeof(t_zone), size);
            return BYT(last_zone->next->blocks) + sizeof(t_block);
        }
    }
}

/**
 * Allocates a memory zone of the given size
 * @param size The size of the memory zone to allocate
 */
void *malloc(size_t size)
{
    // ft_putstr_fd("\033[31mft_malloc called\033[37;0m\n", 2);
    if (size == 0)
        return NULL;

    void *ptr;

    if (size <= TINY_LIMIT) {
        ptr = get_tiny_address(size);
    }
    else if (size <= SMALL_LIMIT) {
        ptr = get_small_address(size);
    }
    else {
        ptr = get_large_address(size);
    }

    if (ptr == MAP_FAILED)
        return NULL;
    
    return ptr;
}