#include "libft_malloc.h"

t_zones g_zones = {.tiny = NULL, .small = NULL, .large = NULL};


/**
 * Creates a new block of memory
 * @param ptr The pointer to the memory zone allocated with mmap
 * @param type The type of the memory zone (TINY, SMALL, LARGE)
 * @param size The size of the memory zone
 */
t_zone *new_zone(e_zone_type type)
{
    void *ptr;

    if (type == TINY)
        ptr = MMAP(0, 4 * getpagesize());
    else if (type == SMALL)
        ptr = MMAP(0, SMALL_SIZE);
    else if (type == LARGE)
        ptr = MMAP(0, )
}

/**
 * Displays an unsigned long integer (address) on the standard output 
 * in hexadecimal format
 * @param n The address to display
 */
void ft_puthex(unsigned long int n)
{
    char *hex = "0123456789abcdef";
    if (n >= 16)
        ft_puthex(n / 16);
    ft_putchar_fd(hex[n % 16], 1);
}


void *get_tiny_address()
{
    if (g_zones.tiny == NULL)
    {
        g_zones.tiny = new_zone(TINY);
    }

}

/**
 * Allocates a memory zone of the given size
 * @param size The size of the memory zone to allocate
 */
void *ft_malloc(size_t size)
{
    if (size == 0)
        return NULL;

    void *ptr;
    void *hint;

    if (size <= TINY_LIMIT) {
        ptr = get_tiny_address();
    }

    if (ptr == MAP_FAILED)
        return NULL;
    
    return ptr;
}

/**
 * Displays the state of the allocated memory zone
 */
void show_alloc_mem(void)
{
    ft_putstr_fd("TINY : 0x", 1);
    ft_puthex((unsigned long int)g_zones.tiny);
    ft_putchar_fd('\n', 1);
}