#include "../inc/libft_malloc.h"

/**
    * Erases all the empty zones from the zone list
    * @param zone_list The list of zones to check (tiny or small)
*/
void erase_empty_zones(t_zone *zone_list)
{
    t_zone *zone = zone_list;
    int zone_empty;
    t_block *block;
    t_zone *tmp_next;

    while(zone)
    {
        // do not unmap the first zone of each type to preserve the global variable
        if (zone == (t_zone *)g_zones.small || zone == (t_zone *)g_zones.tiny) {
            zone = zone->next;
            continue ;
        }
        zone_empty = 1;
        block = zone->blocks;
        tmp_next = zone->next;
        while (block)
        {
            if (block->free == 0)
            {
                zone_empty = 0;
                break ;
            }
            block = block->next;
        }
        if (zone_empty)
        {
            if (zone == zone_list && zone->next)
                zone_list = zone->next;
            else if (zone == zone_list && !zone->next)
            {
                if (zone_list == g_zones.tiny)
                    g_zones.tiny = NULL;
                else if (zone_list == g_zones.small)
                    g_zones.small = NULL;
            }
            else
            {
                t_zone *prev = zone_list;
                while (prev->next != zone)
                    prev = prev->next;
                prev->next = zone->next;
            }
            tmp_next = zone->next;
            munmap(zone, zone->size);
        }
        zone = tmp_next;
    }
}

void try_merge_blocks(t_block *block_freed)
{
    // try to merge with previous block
    if (block_freed->prev && block_freed->prev->free)
    {
        block_freed->prev->size += block_freed->size + sizeof(t_block);
        block_freed->prev->next = block_freed->next;
        if (block_freed->next)
            block_freed->next->prev = block_freed->prev;        
    }
    // try to merge with next block
    else if (block_freed->next && block_freed->next->free)
    {
        block_freed->size += block_freed->next->size + sizeof(t_block);
        block_freed->next = block_freed->next->next;
        if (block_freed->next)
            block_freed->next->prev = block_freed->prev;        
    }
}

/**
 * Frees empty zones in the large zone list
*/
static void free_large_zone(t_zone *zone)
{
    if (zone == NULL)
        return ;
    else if (zone == g_zones.large)
        g_zones.large = zone->next;
    else
    {
        t_zone *prev = g_zones.large;
        while (prev->next != zone)
            prev = prev->next;
        prev->next = zone->next;
    }
    munmap(zone, sizeof(t_zone) + zone->size);
}

void occasional_cleanup()
{
    static int calls = 0;

    if (calls++ > 10)
    {
        erase_empty_zones(g_zones.tiny);
        erase_empty_zones(g_zones.small);
        calls = 0;
    }
}

void free(void *ptr)
{
    t_block *block;
    t_zone *zone;

    if (ptr == NULL)
        return ;
    block = search_addr(g_zones.tiny, ptr);
    if (block)
    {
        block->free = 1;
        try_merge_blocks(block);
        occasional_cleanup();
        return ;
    }
    block = search_addr(g_zones.small, ptr);
    if (block)
    {
        block->free = 1;
        try_merge_blocks(block);
        occasional_cleanup();
        return ;
    }
    zone = search_large_addr(ptr);
    free_large_zone(zone);
}