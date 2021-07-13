#include "libft.h"

void	ft_lstdelone(t_list *lst)
{
	if (lst)
		free(lst);
	lst = NULL;
}
