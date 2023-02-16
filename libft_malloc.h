#ifndef LIBFT_MALLOC_H
#define LIBFT_MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"



# define TINY_LIMIT 128
# define SMALL_LIMIT 4096



void ft_free(void *ptr);
void *ft_malloc(size_t size);
void *ft_realloc(void *ptr, size_t size);

// Display the state of the allocated memory zone
void show_alloc_mem();

typedef struct s_zones
{
    void *tiny;
    void *small;
    void *large;
} t_zones;

extern t_zones g_zones;

#endif