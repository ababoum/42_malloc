#ifndef LIBFT_MALLOC_H
#define LIBFT_MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"


# define TINY_LIMIT 128
# define SMALL_LIMIT 512


# define MMAP(addr, size) mmap(addr, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)

void ft_free(void *ptr);
void *ft_malloc(size_t size);
void *ft_realloc(void *ptr, size_t size);

void show_alloc_mem();


enum e_zone_type
{
    TINY,
    SMALL,
    LARGE
};

// a block is a piece of memory returned by malloc
typedef struct s_block
{
    size_t size;
    struct s_block *next;
    struct s_block *prev;
    int free;
} t_block;

// a zone is composed of a list of pages
typedef struct s_zone
{
    size_t size;
    struct s_zone *next;
    struct s_zone *prev;
    t_block *blocks;
} t_zone;

// global structure containing the beginning of all the zones
typedef struct s_zones
{
    t_zone *tiny;
    t_zone *small;
    t_zone *large;
} t_zones;


extern t_zones g_zones;

#endif