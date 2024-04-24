#include "libft.h"

static	char	is_set(char c,	char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	s1_len;
	int	s2_len;
	char	*s2;

	s1_len = ft_strlen(s1);
	i = 0;
	j = s1_len
	if (!s1)
		return (0);
	while (is_set(s1[i], (char *)set))
		i++;
	while (is_set(s1[--j], (char *)set))
		if (j == 0)
			break ;
	s2_len = (s1_len - i) - (s1_len - j) + 2;
	if (s2_len < 1)
		s2_len = 1;
	s2 = ft_calloc(s2_len, sizeof(char));
	if (!s2)
		return (0);
	ft_strlcpy(s2, (char *)&s1[i], s2_len);
	return (s2);
}