#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (lst)
	{	
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst);
			(*lst) = tmp;
		}
	}
}
