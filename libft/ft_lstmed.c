#include "libft.h"

int	ft_lstmed(t_list *lst)
{
	t_list	*tmp;
	int		sum;
	int		index;

	index = 0;
	sum = 0;
	tmp = lst;
	while (tmp)
	{
		sum += tmp->data;
		index++;
		tmp = tmp->next;
	}
	return (sum/index);
}
