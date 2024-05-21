#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    void    *ptr;
    const size_t     protect = count * size;

    if (count && protect / size != size)
        return (0);
    ptr = malloc(count * size);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, (count * size));
    return (ptr);
}
