#ifndef LIBFT_MALLOC_H
#define LIBFT_MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>


# define TINY_LIMIT 128
# define SMALL_LIMIT 512


# define MMAP(addr, size) mmap(addr, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)
# define BYT(ptr) (char *)ptr

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

void show_alloc_mem();

// Utils
void ft_puthex(unsigned long int n);
void ft_putchar_fd(char c, int fd);
size_t ft_strlen(const char *str);
void ft_putstr_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);

typedef enum e_zone_type
{
    TINY,
    SMALL,
    LARGE
} e_zone_type;

// a block is a piece of memory (inside a zone) returned by malloc
typedef struct s_block
{
    size_t size;
    struct s_block *next;
    int free;
} t_block;

// a zone is a memory area containing blocks
typedef struct s_zone
{
    size_t size;
    struct s_zone *next;
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