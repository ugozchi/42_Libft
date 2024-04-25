#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (str[i] != (unsigned char)c)
	{
		if (i == 0 && str[i] != c)
			return ((char *) 0);
		i--;
	}
	return ((char *) &str[i]);
}
