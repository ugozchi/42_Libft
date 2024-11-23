/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:27:10 by uzanchi           #+#    #+#             */
/*   Updated: 2024/11/18 12:19:16 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdelone(t_list_bonus *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}
