#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			sign *= -1;
	}
	while (ft_isdigit(*nptr))
		result = result * 10 + *nptr++ - '0';
	return (result * sign);
}
