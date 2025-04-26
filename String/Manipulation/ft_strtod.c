/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:42:38 by uzanchi           #+#    #+#             */
/*   Updated: 2025/04/26 18:57:26 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static const char	*parse_sign_and_skip(const char *p, int *sign)
{
	while (ft_isspace(*p))
		p++;
	if (*p == '+' || *p == '-')
	{
		if (*p == '-')
			*sign = -1;
		p++;
	}
	return (p);
}

static const char	*parse_main_number(const char *p, double *result, int *seen)
{
	double	fraction;

	while (ft_isdigit(*p))
	{
		*seen = 1;
		*result = *result * 10.0 + (*p - '0');
		p++;
	}
	fraction = 1.0;
	if (*p == '.')
	{
		p++;
		while (ft_isdigit(*p))
		{
			*seen = 1;
			fraction *= 0.1;
			*result += (*p - '0') * fraction;
			p++;
		}
	}
	return (p);
}

static const char	*parse_exponent(const char *p, int *exponent)
{
	int	sign;
	int	value;

	sign = 1;
	value = 0;
	if (*p == 'e' || *p == 'E')
	{
		p++;
		if (*p == '+')
			p++;
		else if (*p == '-')
		{
			sign = -1;
			p++;
		}
		while (ft_isdigit(*p))
		{
			value = value * 10 + (*p - '0');
			p++;
		}
	}
	*exponent = sign * value;
	return (p);
}

static void	final_adjust(double *result, int exponent, int sign)
{
	if (exponent != 0)
		*result *= pow(10.0, exponent);
	*result *= sign;
	if (*result != 0.0 && !isfinite(*result))
		errno = ERANGE;
}

double	ft_strtod(const char *nptr, char **endptr)
{
	const char	*p;
	double		result;
	int			sign;
	int			exponent;
	int			seen_digit;

	result = 0.0;
	sign = 1;
	exponent = 0;
	seen_digit = 0;
	p = nptr;
	if (handle_special_case(nptr, endptr, &result))
		return (result);
	p = parse_sign_and_skip(p, &sign);
	p = parse_main_number(p, &result, &seen_digit);
	p = parse_exponent(p, &exponent);
	final_adjust(&result, exponent, sign);
	if (endptr != NULL)
	{
		if (seen_digit)
			*endptr = (char *)p;
		else
			*endptr = (char *)nptr;
	}
	return (result);
}
