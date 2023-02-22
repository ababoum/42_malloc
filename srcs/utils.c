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
    int *d_i;
    const int *s_i;
    char *d_c;
    const char *s_c;

    d_i = dest;
    s_i = src;
    while (n-- > sizeof(int))
        *d_i++ = *s_i++;
    d_c = (char *)d_i;
    s_c = (char *)s_i;
    while (n-- > 0)
        *d_c++ = *s_c++;
    return dest;
}

size_t min(size_t a, size_t b)
{
    if (a < b)
        return a;
    return b;
}