#include "push_swap.h"

void	from_array(char **argv, t_list **a)
{
	int		i;
	int		i1;
	int		nbr;
	char	**pre_stack;

	i = 1;
	if (argv[i] == NULL)
		ft_putendl_fd("Not enough arguments", 1);
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

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	(void)argc;
	from_array(argv, &stack.a);
	if (!check_sort(stack.a))
		return (0);
	sort(&stack);
	return (0);
}
