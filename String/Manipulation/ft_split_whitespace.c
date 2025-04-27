/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:33:24 by uzanchi           #+#    #+#             */
/*   Updated: 2025/04/27 14:44:16 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// /* Count words based on delimiter function */
// static int	count_words(const char *str, bool (*is_delim)(char, void *),
// 		void *context)
// {
// 	int	count;
// 	int	in_word;

// 	count = 0;
// 	in_word = 0;
// 	while (*str)
// 	{
// 		if (!is_delim(*str, context) && !in_word)
// 		{
// 			in_word = 1;
// 			count++;
// 		}
// 		else if (is_delim(*str, context))
// 			in_word = 0;
// 		str++;
// 	}
// 	return (count);
// }

// /* Extract a single word based on delimiter */
// static char	*extract_word(const char *str, bool (*is_delim)(char, void *),
// 		void *context, int *i)
// {
// 	int		start;
// 	int		end;
// 	char	*word;

// 	while (is_delim(str[*i], context))
// 		(*i)++;
// 	start = *i;
// 	while (str[*i] && !is_delim(str[*i], context))
// 		(*i)++;
// 	end = *i;
// 	word = malloc((end - start + 1) * sizeof(char));
// 	if (!word)
// 		return (NULL);
// 	ft_strncpy(word, str + start, end - start);
// 	word[end - start] = '\0';
// 	return (word);
// }

// /* Generic split function using delimiter function */
// static char	**ft_split_generic(const char *str, bool (*is_delim)(char, void *),
// 		void *context)
// {
// 	int		word_count;
// 	char	**result;
// 	int		i;
// 	int		j;

// 	if (!str)
// 		return (NULL);
// 	word_count = count_words(str, is_delim, context);
// 	result = malloc((word_count + 1) * sizeof(char *));
// 	if (!result)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (j < word_count)
// 	{
// 		result[j] = extract_word(str, is_delim, context, &i);
// 		if (!result[j])
// 		{
// 			while (j > 0)
// 				free(result[--j]);
// 			free(result);
// 			return (NULL);
// 		}
// 		j++;
// 	}
// 	result[j] = NULL;
// 	return (result);
// }

// /* Wrapper for whitespace check */
// static bool	is_whitespace_wrapper(char c, void *context)
// {
// 	(void)context;
// 	return (ft_isspace(c));
// }

// /* Split by whitespace */
// char	**ft_split_whitespace(const char *str)
// {
// 	return (ft_split_generic(str, is_whitespace_wrapper, NULL));
// }

static int	count_words(const char *str, bool (*is_delim)(char, void *),
		void *context)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_delim(*str, context) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_delim(*str, context))
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*extract_word(const char *str, bool (*is_delim)(char, void *),
		void *context, int *i)
{
	int		start;
	int		end;
	char	*word;

	while (is_delim(str[*i], context))
		(*i)++;
	start = *i;
	while (str[*i] && !is_delim(str[*i], context))
		(*i)++;
	end = *i;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strncpy(word, str + start, end - start);
	word[end - start] = '\0';
	return (word);
}

static void	free_split(char **result, int j)
{
	while (j > 0)
		free(result[--j]);
	free(result);
}

static char	**ft_split_generic(const char *str, bool (*is_delim)(char, void *),
		void *context)
{
	int		word_count;
	char	**result;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	word_count = count_words(str, is_delim, context);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count)
	{
		result[j] = extract_word(str, is_delim, context, &i);
		if (!result[j])
			return (free_split(result, j), NULL);
		j++;
	}
	result[j] = NULL;
	return (result);
}

static bool	is_whitespace(char c, void *context)
{
	(void)context;
	return (ft_isspace(c));
}

char	**ft_split_whitespace(const char *str)
{
	return (ft_split_generic(str, is_whitespace, NULL));
}
