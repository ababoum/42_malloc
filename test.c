#include "libft_malloc.h"

int main()
{
    char *test;

    test = ft_malloc(10);
    test[0] = 'a';
    test[1] = 'b';
    test[2] = 'c';
    test[3] = 'd';
    test[4] = 'e';
    test[5] = 0;

    printf("test: %s\n", test);
    // ft_free(test);

    char *test2;

    test2 = ft_malloc(10);
    test2[0] = 'a';
    test2[1] = 'b';
    test2[2] = 'c';
    test2[3] = 'd';
    test2[4] = 'e';
    test2[5] = 0;

    printf("test2: %s\n", test);

    show_alloc_mem();

    return (0);
}