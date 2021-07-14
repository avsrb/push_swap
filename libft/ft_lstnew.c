#include "libft.h"

t_list	*ft_lstnew(int data)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->data = data;
	data++;
	elem->next = 0;
	return (elem);
}
