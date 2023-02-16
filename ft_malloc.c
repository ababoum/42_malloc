#include "libft_malloc.h"

t_zones g_zones = {.tiny = NULL, .small = NULL, .large = NULL};


void ft_puthex(unsigned long int n)
{
    char *hex = "0123456789abcdef";
    if (n >= 16)
        ft_puthex(n / 16);
    ft_putchar_fd(hex[n % 16], 1);
}

void *ft_malloc(size_t size)
{
    if (size == 0)
        return NULL;

    void *ptr;
    void *hint;

    if (size <= TINY_LIMIT) {
        hint = g_zones.tiny == NULL ? NULL : g_zones.tiny + size;
        ptr = mmap(hint, size,
                            PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE,
                            -1, 0);
        if (g_zones.tiny == NULL) {
            g_zones.tiny = ptr;
        }
    }

    if (ptr == MAP_FAILED)
        return NULL;
    
    return ptr;
}


void show_alloc_mem(void)
{
    ft_putstr_fd("TINY : 0x", 1);
    ft_puthex((unsigned long int)g_zones.tiny);
    ft_putchar_fd('\n', 1);
}