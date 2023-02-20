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

int search_addr(t_zone *zone_list, void *ptr)
{
    t_zone *zone = zone_list;
    while (zone)
    {
        t_block *block = zone->blocks;
        while (block)
        {
            if (BYT(block) + sizeof(t_block) == ptr)
            {
                block->free = 1;
                return 1;
            }
            block = block->next;
        }
        zone = zone->next;
    }
    return 0;
}

void search_large_addr(void *ptr)
{
    t_zone *zone = g_zones.large;
    while (zone)
    {
        if (BYT(zone) + sizeof(t_zone) == ptr)
        {
            if (zone == g_zones.large)
                g_zones.large = zone->next;
            else
            {
                t_zone *prev = g_zones.large;
                while (prev->next != zone)
                    prev = prev->next;
                prev->next = zone->next;
            }
            munmap(zone, sizeof(t_zone) + zone->size);
            return ;
        }
        zone = zone->next;
    }
}

void free(void *ptr)
{
    if (ptr == NULL)
        return ;

    // look for the block in the zones
    if (search_addr(g_zones.tiny, ptr))
        return ;
    else if (search_addr(g_zones.small, ptr))
        return ;
    else
        search_large_addr(ptr);
}