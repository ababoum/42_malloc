#include "libft_malloc.h"

t_zones g_zones = {.tiny = NULL, .small = NULL, .large = NULL};


t_block *new_block(void *starting_addr, size_t size)
{
    t_block *block = (t_block *)starting_addr;
    block->size = size;
    block->next = NULL;
    block->free = 0;
    return block;
}

/**
 * Creates a new block of memory
 * @param ptr The pointer to the memory zone allocated with mmap
 * @param type The type of the memory zone (TINY, SMALL, LARGE)
 * @param size The size of the memory zone
 */
t_zone *new_zone(e_zone_type type, size_t size)
{
    void *ptr;

    if (type == TINY) {
        ptr = MMAP(0, 4 * getpagesize());
        size = 4 * getpagesize();
    }
    else if (type == SMALL) {
        ptr = MMAP(0, 16 * getpagesize());
        size = 16 * getpagesize();
    }
    else if (type == LARGE)
        ptr = MMAP(0, size);

    if (ptr == MAP_FAILED)
        return NULL;

    t_zone *zone = (t_zone *)ptr;
    zone->size = size;
    zone->next = NULL;
    zone->blocks = NULL;
    return zone;
}

t_zone *go_to_last_zone(t_zone *start)
{
    t_zone *zone = start;
    while (zone->next)
        zone = zone->next;
    return zone;
}

t_block *go_to_last_block(t_block *start)
{
    t_block *block = start;
    while (block->next)
        block = block->next;
    return block;
}

size_t net_remaining_space(t_zone *zone)
{
    size_t remaining_space = zone->size - sizeof(t_zone);
    t_block *block = zone->blocks;
    while (block)
    {
        remaining_space -= block->size + sizeof(t_block);
        block = block->next;
    }
    return remaining_space;
}

void *get_tiny_address(size_t size)
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
        t_zone *last_zone = go_to_last_zone(g_zones.tiny);
        t_block *last_block = go_to_last_block(last_zone->blocks);
        if (net_remaining_space(last_zone) >= size + sizeof(t_block))
        {
            last_block->next = new_block(last_block + sizeof(t_block) + last_block->size, size);
            return BYT(last_block->next) + sizeof(t_block);
        }
        else
        {
            last_zone->next = new_zone(TINY, size);
            if (last_zone->next == NULL)
                return NULL;
            last_zone->next->blocks = new_block(last_zone->next + sizeof(t_zone), size);
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
    if (size == 0)
        return NULL;

    void *ptr;

    if (size <= TINY_LIMIT) {
        ptr = get_tiny_address(size);
    }

    if (ptr == MAP_FAILED)
        return NULL;
    
    return ptr;
}