/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:39:48 by uzanchi           #+#    #+#             */
/*   Updated: 2024/11/18 12:19:27 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list_bonus	*ft_lstnew(void *content)
{
	t_list_bonus	*list;

	list = malloc(sizeof(t_list_bonus));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
