#include "libft_malloc.h"

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

t_block* search_addr(t_zone *zone_list, void *ptr)
{
    t_zone *zone = zone_list;
    while (zone)
    {
        t_block *block = zone->blocks;
        while (block)
        {
            if (BYT(block) + sizeof(t_block) == ptr)
            {
                return block;
            }
            block = block->next;
        }
        zone = zone->next;
    }
    return 0;
}

t_zone *search_large_addr(void *ptr)
{
    t_zone *zone = g_zones.large;
    while (zone)
    {
        if (BYT(zone) + sizeof(t_zone) == ptr)
        {
            return zone;
        }
        zone = zone->next;
    }
    return NULL;
}