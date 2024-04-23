#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]) && i < (n -1))
		i++;
	if (n < 1)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
} 
