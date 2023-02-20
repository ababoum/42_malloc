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

    size_t qty_to_copy = 0;
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
                qty_to_copy = min(zone->size, size);
            else
                return NULL;
        }
    }
    if (qty_to_copy == size)
    {
        if (block)
            block->size = size;
        else
            zone->size = size;
        return ptr;
    }
    void *new_ptr = malloc(size);
    if (new_ptr == NULL)
        return NULL;
    ft_memcpy(new_ptr, ptr, qty_to_copy);
    free(ptr);
    return new_ptr;
}