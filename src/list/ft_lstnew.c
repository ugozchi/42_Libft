#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}