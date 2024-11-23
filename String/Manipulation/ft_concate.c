/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:52:28 by uzanchi           #+#    #+#             */
/*   Updated: 2024/11/18 12:25:48 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static size_t	get_final_length(size_t n, va_list ap)
{
	va_list	ap_copy;
	size_t	i;
	size_t	length;

	va_copy(ap_copy, ap);
	i = 0;
	length = 0;
	while (i++ < n)
		length += ft_strlen(va_arg(ap_copy, char *));
	va_end(ap_copy);
	return (length);
}

static size_t	add_string(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

char	*ft_concate(size_t n, ...)
{
	va_list	ap;
	size_t	final_length;
	size_t	i;
	size_t	j;
	char	*concat;

	va_start(ap, n);
	final_length = get_final_length(n, ap);
	concat = malloc((final_length + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	i = 0;
	j = 0;
	while (i++ < n)
		j += add_string(&concat[j], va_arg(ap, char *));
	va_end(ap);
	concat[j] = '\0';
	return (concat);
}