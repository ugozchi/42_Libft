#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	length;
	char	*output;
	size_t	index;

	length = ft_strlen(s);
	output = malloc((length + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	index = 0;
	while (index < length)
	{
		output[index] = f(index, s[index]);
		index++;
	}
	output[index] = '\0';
	return (output);
}