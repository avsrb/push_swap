#include "./../include/push_swap.h"

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
	int		i;
	int		flag_sign;

	flag_sign = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			flag_sign += 1;
		else if (str[i] >= '0' && str[i] <= '9')
			;
		else
			ft_error(0);
		if (flag_sign > 1)
			ft_error(0);
		i++;
	}
}
