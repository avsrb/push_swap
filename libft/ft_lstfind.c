#include "libft.h"

int	ft_lstfindindex(t_list *lst, int f)
{
	t_list	*tmp;
	int		index;

	index = 1;
	tmp = lst;
	while (tmp && tmp->data != f)
	{
		tmp = tmp->next;
		index++;
	}
	return (index);
}
