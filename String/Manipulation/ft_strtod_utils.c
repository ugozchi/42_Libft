/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:06:11 by uzanchi           #+#    #+#             */
/*   Updated: 2025/04/26 19:11:58 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	check_infinity(const char **p, char **endptr, double *result)
{
	if (ft_tolower(**p) == 'i' && ft_tolower(*(*p + 1)) == 'n'
		&& ft_tolower(*(*p + 2)) == 'f')
	{
		*p += 3;
		if (ft_tolower(**p) == 'i' && ft_tolower(*(*p + 1)) == 'n'
			&& ft_tolower(*(*p + 2)) == 'i' && ft_tolower(*(*p + 3)) == 't'
			&& ft_tolower(*(*p + 4)) == 'y')
			*p += 5;
		*result = INFINITY;
		if (endptr != NULL)
			*endptr = (char *)(*p);
		return (1);
	}
	return (0);
}

static int	check_nan(const char **p, char **endptr, double *result)
{
	if (ft_tolower(**p) == 'n' && ft_tolower(*(*p + 1)) == 'a'
		&& ft_tolower(*(*p + 2)) == 'n')
	{
		*p += 3;
		*result = NAN;
		if (endptr != NULL)
			*endptr = (char *)(*p);
		return (1);
	}
	return (0);
}

int	handle_special_case(const char *nptr, char **endptr, double *result)
{
	const char	*p;

	p = nptr;
	if (check_infinity(&p, endptr, result))
		return (1);
	if (check_nan(&p, endptr, result))
		return (1);
	return (0);
}
