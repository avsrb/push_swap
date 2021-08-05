#include "libft.h"

int		ft_lstfind(t_list *lst, int f)
{
	t_list	*tmp;
	int	index;

	index = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->data == f)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (0);
}
