/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:31:40 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/14 17:42:49 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	if (str == NULL)
		return (0);
	length = 0;
	while (*str++)
		length++;
	return (length);
}
/*
#include <stdio.h>

int	main()
{
	const char *string;

	string = NULL;
	printf("%ld\n", ft_strlen(string));
}
*/
