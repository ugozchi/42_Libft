/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:36:42 by uzanchi           #+#    #+#             */
/*   Updated: 2025/04/26 19:39:19 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// char	*ft_strtok(char *str, const char *delim)
// {
// 	static char	*save_ptr = NULL;
// 	char		*token_start;

// 	if (str == NULL)
// 	{
// 		if (save_ptr == NULL || *save_ptr == '\0')
// 			return (NULL);
// 		str = save_ptr;
// 	}
// 	while (*str && ft_strchr(delim, *str))
// 		str++;
// 	if (!*str)
// 	{
// 		save_ptr = NULL;
// 		return (NULL);
// 	}
// 	token_start = str;
// 	while (*str && !ft_strchr(delim, *str))
// 		str++;
// 	if (*str)
// 	{
// 		*str = '\0';
// 		save_ptr = str + 1;
// 	}
// 	else
// 	{
// 		save_ptr = NULL;
// 	}
// 	return (token_start);
// }

static char	*skip_delimiters(char *str, const char *delim)
{
	while (*str && ft_strchr(delim, *str))
		str++;
	return (str);
}

static char	*find_token_end(char *str, const char *delim)
{
	while (*str && !ft_strchr(delim, *str))
		str++;
	return (str);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*save_ptr = NULL;
	char		*token_start;

	if (str == NULL)
	{
		if (save_ptr == NULL || *save_ptr == '\0')
			return (NULL);
		str = save_ptr;
	}
	str = skip_delimiters(str, delim);
	if (!*str)
	{
		save_ptr = NULL;
		return (NULL);
	}
	token_start = str;
	str = find_token_end(str, delim);
	if (*str)
	{
		*str = '\0';
		save_ptr = str + 1;
	}
	else
		save_ptr = NULL;
	return (token_start);
}
