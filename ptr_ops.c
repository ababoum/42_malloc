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