#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0)
	{
		while (*s)
			write(fd, s++, 1);
	}
}