#include "libft_malloc.h"

void	*ft_realloc(void *ptr, size_t size)
{
    if (ptr == NULL)
        return ft_malloc(size);

    if (size == 0)
    {
        ft_free(ptr);
        return NULL;
    }

    return NULL;
}