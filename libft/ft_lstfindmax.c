#include "libft.h"

int	ft_lstfindmax(t_list *lst)
{
	t_list	*tmp;
	tmp = lst;
	int	max;

	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}