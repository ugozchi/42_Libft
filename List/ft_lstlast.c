/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:32:16 by uzanchi           #+#    #+#             */
/*   Updated: 2024/11/18 12:19:22 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list_bonus	*ft_lstlast(t_list_bonus *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
