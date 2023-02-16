#include "libft_malloc.h"

t_zones g_zones = {.tiny = NULL, .small = NULL, .large = NULL};


/**
 * Creates a new block of memory
 * @param ptr The pointer to the memory zone allocated with mmap
 * @param type The type of the memory zone (TINY, SMALL, LARGE)
 * @param size The size of the memory zone
 */
t_block *new_block(void *ptr, e_zone type, size_t size)
{
    t_block *block = (t_block *)MMAP(NULL, sizeof(t_block));
    block->next = NULL;
    block->prev = NULL;
    block->size = size;
    block->ptr = ptr;
    block->free = 1;
    block->type = type;
    return block;
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

/**
 * Displays the state of the allocated memory zone
 */
void show_alloc_mem(void)
{
    ft_putstr_fd("TINY : 0x", 1);
    ft_puthex((unsigned long int)g_zones.tiny);
    ft_putchar_fd('\n', 1);
}