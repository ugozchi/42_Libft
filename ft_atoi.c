#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		result;

	sign = 1;
	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			sign *= -1;
	}
	while (ft_isdigit(*nptr))
	{
		if (result > INT_MAX / 10
			|| (result == INT_MAX / 10 && *nptr - '0' > INT_MAX % 10))
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		result = result * 10 + *nptr++ - '0';
	}
	return (result * sign);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	printf("%d\n", ft_atoi(av[1]));
}
*/