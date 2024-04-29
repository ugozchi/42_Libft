#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd >= 0)
	{
		while (*s)
			write(fd, s++, 1);
	}
	return ;
}
