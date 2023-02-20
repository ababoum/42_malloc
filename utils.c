#include "libft_malloc.h"

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