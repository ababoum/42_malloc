#include "libft_malloc.h"

/**
 * Displays the state of the allocated memory zone
 */

static void show_block_mem(t_block *block)
{
    ft_putstr_fd("0x", 1);
    ft_puthex((unsigned long int)block);
    ft_putstr_fd(" - 0x", 1);
    ft_puthex((unsigned long int)block + block->size + sizeof(t_block));
    ft_putstr_fd(" : ", 1);
    ft_putnbr_fd(block->size, 1);
    ft_putstr_fd(" bytes\n", 1);
}

void show_alloc_mem(void)
{
    ft_putstr_fd("TINY : 0x", 1);
    ft_puthex((unsigned long int)g_zones.tiny);
    ft_putchar_fd('\n', 1);
    t_zone *zone = g_zones.tiny;
    while (zone)
    {
        t_block *block = zone->blocks;
        while (block)
        {
            show_block_mem(block);
            block = block->next;
        }
        zone = zone->next;
    }
}