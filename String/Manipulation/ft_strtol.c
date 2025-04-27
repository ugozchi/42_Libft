/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:51:10 by uzanchi           #+#    #+#             */
/*   Updated: 2025/04/27 12:55:13 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	update_acc(unsigned long *acc, int base, int val)
{
	*acc = *acc * (unsigned long)base + (unsigned long)val;
}

static void	update_endptr(char **endptr, const char *nptr,
		const char *s, int any)
{
	if (endptr != NULL)
	{
		if (any)
			*endptr = (char *)s;
		else
			*endptr = (char *)nptr;
	}
}

static long	final_result(t_parse *p, int any)
{
	if (any < 0)
	{
		if (p->neg)
			return (LONG_MIN);
		else
			return (LONG_MAX);
	}
	if (p->neg)
		return ((long)(-p->acc));
	return ((long)p->acc);
}

static int	parse_digits(t_parse *p)
{
	int	any;
	int	val;
	int	c;

	any = 0;
	c = *(p->s);
	while (1)
	{
		val = char_to_val(c);
		if (!check_val(val, p->base))
			break ;
		if (check_overflow(p->acc, val, p->cutoff, p->cutlim))
			any = -1;
		else
		{
			any = 1;
			update_acc(&p->acc, p->base, val);
		}
		p->s++;
		c = *(p->s);
	}
	return (any);
}

long int	ft_strtol(const char *nptr, char **endptr, int base)
{
	t_parse	p;
	int		any;

	p.s = skip_whitespace(nptr);
	p.neg = 0;
	p.acc = 0;
	p.base = base;
	p.s = parse_sign(p.s, &p.neg);
	if (p.base == 0)
		p.s = parse_base(p.s, &p.base);
	compute_cutoff(&p);
	any = parse_digits(&p);
	update_endptr(endptr, nptr, p.s, any);
	return (final_result(&p, any));
}

// long int	ft_strtol(const char *nptr, char **endptr, int base)
// {
// 	const char			*s = nptr;
// 	unsigned long int	acc;
// 	int					c;
// 	unsigned long int	cutoff;
// 	int					neg;
// 	int					any;
// 	int					cutlim;

// 	neg = 0;
// 	any = 0;
// 	cutlim = 0;
// 	// Étape 1 : Gestion des espaces blancs initiaux
// 	do
// 	{
// 		c = *s++;
// 	} while (ft_isspace(c));
// 	// Étape 2 : Gestion du signe éventuel
// 	if (c == '-')
// 	{
// 		neg = 1;
// 		c = *s++;
// 	}
// 	else if (c == '+')
// 	{
// 		c = *s++;
// 	}
// 	// Étape 3 : Vérification de la base
// 	if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X'))
// 	{
// 		c = s[1];
// 		s += 2;
// 		base = 16;
// 	}
// 	else if (base == 0)
// 	{
// 		base = (c == '0') ? 8 : 10;
// 	}
// 	// Étape 4 : Calcul des valeurs de coupure
// 	cutoff = neg ? -(unsigned long int)LONG_MIN : LONG_MAX;
// 	cutlim = cutoff % (unsigned long int)base;
// 	cutoff /= (unsigned long int)base;
// 	// Étape 5 : Conversion des chiffres
// 	for (acc = 0, any = 0;; c = *s++)
// 	{
// 		if (ft_isdigit(c))
// 			c -= '0';
// 		else if (ft_isalpha(c))
// 			c -= ft_isupper(c) ? 'A' - 10 : 'a' - 10;
// 		else
// 			break ;
// 		if (c >= base)
// 			break ;
// 		if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
// 			any = -1;
// 		else
// 		{
// 			any = 1;
// 			acc *= base;
// 			acc += c;
// 		}
// 	}
// 	// Étape 6 : Gestion des cas d'erreur et de fin
// 	if (any < 0)
// 	{
// 		acc = neg ? LONG_MIN : LONG_MAX;
// 		// errno = ERANGE;
// 	}
// 	else if (neg)
// 		acc = -acc;
// 	if (endptr != NULL)
// 		*endptr = (char *)(any ? s - 1 : nptr);
// 	return (acc);
// }