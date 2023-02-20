#include "libft_malloc.h"

/**
 * Displays the state of the allocated memory zone
 * @param block The block to display
 */

static unsigned long int show_block_mem(t_block *block)
{
    unsigned long int total;

    total = 0;
    if (block->free == 0)
    {
        ft_putstr_fd("0x", 1);
        ft_puthex((unsigned long int)block);
        ft_putstr_fd(" - 0x", 1);
        ft_puthex((unsigned long int)block + block->size + sizeof(t_block));
        ft_putstr_fd(" : ", 1);
        ft_putnbr_fd(block->size, 1);
        ft_putstr_fd(" bytes\n", 1);
        total += block->size;
    }
    return total;
}

static unsigned long int show_zone_mem(t_zone *zone_list)
{
    unsigned long int total = 0;
    t_zone *zone = zone_list;
    while (zone)
    {
        t_block *block = zone->blocks;
        while (block)
        {
            total += show_block_mem(block);
            block = block->next;
        }
        zone = zone->next;
    }
    return total;
}

static unsigned long int show_large_zones(void)
{
    unsigned long int total = 0;
    t_zone *zone = g_zones.large;

    while (zone)
    {
        ft_putstr_fd("0x", 1);
        ft_puthex((unsigned long int)zone);
        ft_putstr_fd(" - 0x", 1);
        ft_puthex((unsigned long int)zone + zone->size + sizeof(t_zone));
        total += zone->size;
        ft_putstr_fd(" : ", 1);
        ft_putnbr_fd(zone->size, 1);
        ft_putstr_fd(" bytes\n", 1);
        zone = zone->next;
    }
    return total;
}


/**
 * Displays the state of the allocated memory
*/
void show_alloc_mem(void)
{
    unsigned long int total = 0;

    ft_putstr_fd("TINY : 0x", 1);
    ft_puthex((unsigned long int)g_zones.tiny);
    ft_putchar_fd('\n', 1);
    total += show_zone_mem(g_zones.tiny);
    ft_putstr_fd("SMALL : 0x", 1);
    ft_puthex((unsigned long int)g_zones.small);
    ft_putchar_fd('\n', 1);
    total += show_zone_mem(g_zones.small);
    ft_putstr_fd("LARGE : 0x", 1);
    ft_puthex((unsigned long int)g_zones.large);
    ft_putchar_fd('\n', 1);
    total += show_large_zones();
    ft_putstr_fd("Total : ", 1);
    ft_putnbr_fd(total, 1);
    ft_putstr_fd(" bytes\n", 1);
}