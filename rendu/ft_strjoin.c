#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;

	output = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!output)
		return (NULL);
	while (*s1)
		*output++ = *s1++;
	while (*s2)
		*output++ = *s2++;
	*output = '\0';
	return (output);
}