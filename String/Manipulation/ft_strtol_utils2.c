/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:54:44 by uzanchi           #+#    #+#             */
/*   Updated: 2025/04/27 12:59:55 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

const char	*skip_whitespace(const char *s)
{
	while (ft_isspace(*s))
		s++;
	return (s);
}

const char	*parse_sign(const char *s, int *neg)
{
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			*neg = 1;
		s++;
	}
	return (s);
}
