#ifndef LIBFT_MALLOC_H
#define LIBFT_MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"


# define TINY_LIMIT 128
# define SMALL_LIMIT 4096


# define MMAP(addr, size) mmap(addr, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)

void ft_free(void *ptr);
void *ft_malloc(size_t size);
void *ft_realloc(void *ptr, size_t size);

void show_alloc_mem();

typedef enum e_zone
{
    TINY,
    SMALL,
    LARGE
} e_zone;

typedef struct s_block
{
    size_t size;
    struct s_block *next;
    struct s_block *prev;
    int free;
    void *ptr;
    e_zone type;
} t_block;

typedef struct s_zones
{
    void *tiny;
    void *small;
    void *large;
} t_zones;



extern t_zones g_zones;

#endif