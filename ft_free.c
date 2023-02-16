#include "libft_malloc.h"

void	ft_free(void *ptr)
{
    if (ptr == NULL)
        return ;

    int size = getpagesize();
    printf("size: %d\n", size);
    munmap(ptr, size);
}