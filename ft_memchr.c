#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n && (unsigned char)*ptr != (unsigned char)c)
	{
		ptr++;
		n--;
	}
	if (n)
		return (ptr);
	else
		return (NULL);
}