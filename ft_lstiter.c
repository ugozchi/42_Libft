#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst1;

	if (!lst || !f)
		return ;
	lst1 = lst;
	while (lst1)
	{
		f(lst1->content);
		lst1 = lst1->next;
	}
}