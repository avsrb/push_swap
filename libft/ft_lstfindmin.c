#include "libft.h"

int	ft_lstfindmin(t_list *lst)
{
	t_list	*tmp;
	int		mix;

	tmp = lst;
	mix = tmp->data;
	while (tmp)
	{
		if (tmp->data < mix)
			mix = tmp->data;
		tmp = tmp->next;
	}
	return (mix);
}
