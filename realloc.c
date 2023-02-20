#include "libft_malloc.h"

void	*realloc(void *ptr, size_t size)
{
    if (ptr == NULL)
        return malloc(size);

    if (size == 0)
    {
        free(ptr);
        return NULL;
    }

    int qty_to_copy = 0;
    t_block *block = search_addr(g_zones.tiny, ptr);
    t_zone *zone;
    if (block)
        qty_to_copy = min(block->size, size);
    else
    {
        block = search_addr(g_zones.small, ptr);
        if (block)
            qty_to_copy = min(block->size, size);
        else
        {
            zone = search_large_addr(ptr);
            if (zone)
                qty_to_copy = zone->size;
        }
    }
    (void)qty_to_copy;

    return NULL;
}