#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	char	*haystack_ptr;

	if (!*needle)
		return ((char *) haystack);
	needle_len = ft_strlen(needle);
	haystack_ptr = (char *)haystack;
	while (*haystack_ptr && len >= needle_len)
	{
		if (ft_strncmp(haystack_ptr, needle, needle_len) == 0)
			return (haystack_ptr);
		haystack_ptr++;
		len--;
	}
	return(NULL);
}