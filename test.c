#include "inc/libft_malloc.h"

int main()
{
    char *test;

    test = malloc(10);
    test[0] = 'a';
    test[1] = 'b';
    test[2] = 'c';
    test[3] = 'd';
    test[4] = '\n';
    test[5] = 0;

    ft_putstr_fd(test, 1);

    char *test2;

    test2 = malloc(10);
    test2[0] = 'a';
    test2[1] = 'b';
    test2[2] = 'c';
    test2[3] = 'd';
    test2[4] = '\n';
    test2[5] = 0;

    ft_putstr_fd(test2, 1);
    
    show_alloc_mem();
    free(test);
    free(test2);

    ft_putstr_fd("*******************************\n", 1);

    int i = 0;
    char *addr;

    while (i < 1024)
    {
        addr = (char*)malloc(1024);
        addr[0] = 42;
        free(addr);
        i++;
    }

    show_alloc_mem();

    ft_putstr_fd("*******************************\n", 1);

    char *tab[42];
    for (int i = 0; i < 42; i++)
    {
        tab[i] = (char*)malloc(42);
        tab[i][0] = 42;
    }

    show_alloc_mem();

    ft_putstr_fd("*******************************\n", 1);

    for (int i = 0; i < 42; i++)
    {
        free(tab[i]);
    }

    show_alloc_mem();
    
    return (0);
}