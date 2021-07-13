#include "libft.h"

void	ft_lstfind(t_list *lst, int f)
{
	while (lst)
	{
		if (lst->content == f)
			ft_error();
		lst = lst->next;
	}
	return ;
}
