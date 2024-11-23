/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:33:19 by uzanchi           #+#    #+#             */
/*   Updated: 2024/11/18 12:19:19 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list_bonus *lst, void (*f)(void *))
{
	t_list_bonus	*lst1;

	if (!lst || !f)
		return ;
	lst1 = lst;
	while (lst1)
	{
		f(lst1->content);
		lst1 = lst1->next;
	}
}
