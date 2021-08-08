#include "checker.h"

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

void	from_array(char **argv, t_list **a)
{
	int		i;
	int		i1;
	int		nbr;
	char	**pre_stack;

	i = 1;
	while (argv[i])
	{
		i1 = 0;
		pre_stack = ft_split(argv[i], ' ');
		while (pre_stack[i1] != NULL)
		{
			validation_nbr(pre_stack[i1]);
			nbr = ft_atoi_int(pre_stack[i1]);
			ft_lstfind_error(*a, nbr);
			ft_lstadd_back(a, ft_lstnew(nbr));
			free(pre_stack[i1]);
			i1++;
		}
		free(pre_stack);
		i++;
	}
}

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

void	command(t_stack *st, char *line)
{
	if (!ft_strncmp("ra", line, 3))
		rotate(st, 'a');
	else if (!ft_strncmp("rb", line, 3))
		rotate(st, 'b');
	else if (!ft_strncmp("rr", line, 3))
		rotate(st, 's');
	else if (!ft_strncmp("rra", line, 4))
		reverse_rotate(st, 'a');
	else if (!ft_strncmp("rrb", line, 4))
		reverse_rotate(st, 'b');
	else if (!ft_strncmp("rrr", line, 4))
		reverse_rotate(st, 's');
	else if (!ft_strncmp("pa", line, 3))
		push(st, 'a');
	else if (!ft_strncmp("pb", line, 3))
		push(st, 'b');
	else if (!ft_strncmp("sa", line, 3))
		swap(st, 'a');
	else if (!ft_strncmp("sb", line, 3))
		swap(st, 'b');
	else if (!ft_strncmp("ss", line, 3))
		swap(st, 's');
}

int	main(int argc, char **argv)
{
	t_stack	st;
	char	*line;

	st.a = NULL;
	st.b = NULL;
	(void)argc;
	from_array(argv, &st.a);
	while (get_next_line(1, &line))
	{
		command(&st, line);
		free(line);
	}
	if (!check_sort(st.a) && st.b == NULL)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
