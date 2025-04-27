/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:53:43 by uzanchi           #+#    #+#             */
/*   Updated: 2025/04/27 12:57:54 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

const char	*parse_base(const char *s, int *base)
{
	if (*s == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X'))
	{
		*base = 16;
		return (s + 2);
	}
	if (*s == '0')
		*base = 8;
	else
		*base = 10;
	return (s);
}

void	compute_cutoff(t_parse *p)
{
	if (p->neg)
		p->cutoff = (unsigned long)LONG_MAX + 1;
	else
		p->cutoff = (unsigned long)LONG_MAX;
	p->cutlim = (int)(p->cutoff % (unsigned long)p->base);
	p->cutoff /= (unsigned long)p->base;
}

int	char_to_val(int c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (ft_isupper(c))
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	return (-1);
}

int	check_val(int val, int base)
{
	return (val >= 0 && val < base);
}

int	check_overflow(unsigned long acc, int val, unsigned long cutoff, int cutlim)
{
	if (acc > cutoff)
		return (1);
	if (acc == cutoff && val > cutlim)
		return (1);
	return (0);
}
