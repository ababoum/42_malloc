#include "libft_malloc.h"

/**
    * Erases all the empty zones from the zone list
    * @param zone_list The list of zones to check (tiny or small)
*/
void erase_empty_zones(t_zone *zone_list)
{
    t_zone *zone = zone_list;
    int zone_empty;
    t_block *block;

    while(zone)
    {
        zone_empty = 1;
        block = zone->blocks;
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
            if (zone == zone_list)
                zone_list = zone->next;
            else
            {
                t_zone *prev = zone_list;
                while (prev->next != zone)
                    prev = prev->next;
                prev->next = zone->next;
            }
            munmap(zone, sizeof(t_zone) + zone->size);
        }
        zone = zone->next;
    }
}

/**
 * Frees empty zones in the large zone list
*/
static void free_zone(t_zone *zone)
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
        return ;
    }
    block = search_addr(g_zones.small, ptr);
    if (block)
    {
        block->free = 1;
        return ;
    }
    zone = search_large_addr(ptr);
    free_zone(zone);
    erase_empty_zones(g_zones.tiny);
    erase_empty_zones(g_zones.small);
}