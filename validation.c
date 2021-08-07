#include "push_swap.h"

int	check_sort(t_list *list)
{
	if (!list || !list->next)
		return (0);
	while (list->next)
	{
		if (list->data < list->next->data)
			list = list->next;
		else
			return (1);
	}
	return (0);
}

void	validation_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
			;
		else
			ft_error(0);
		i++;
	}
}
