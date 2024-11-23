/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_set_to_null.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:48:44 by uzanchi           #+#    #+#             */
/*   Updated: 2024/11/18 12:49:11 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	free_and_set_to_null(size_t n, ...)
{
	va_list	ap;
	size_t	i;
	void	*ptr;

	va_start(ap, n);
	i = 0;
	while (i++ < n)
	{
		ptr = va_arg(ap, void *);
		if (ptr)
		{
			free(ptr);
			ptr = NULL;
		}
	}
	va_end(ap);
}