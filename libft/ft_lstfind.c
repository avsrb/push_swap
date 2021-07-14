#include "libft.h"

void	ft_lstfind(t_list *lst, int f)
{
	while (lst)
	{
		if (lst->data == f)
			ft_error(0);
		lst = lst->next;
	}
	return ;
}
