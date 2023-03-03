#include "../inc/libft_malloc.h"

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

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        ((char *)dest)[i] = ((char *)src)[i];
        i++;
    }
    return (dest);
}

size_t min(size_t a, size_t b)
{
    if (a < b)
        return a;
    return b;
}