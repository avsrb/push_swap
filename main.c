#include "push_swap.h"

void	from_array(int argc, char **argv, t_list **a)
{
	int	i;
	int	nbr;

	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv[1] == NULL)
			exit(0);
		i = 0;
	}
	while (argv[i])
	{
		nbr = ft_atoi_int(argv[i]);
		ft_lstfind_error(*a, nbr);
		ft_lstadd_back(a, ft_lstnew(nbr));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (validation(argc, argv))
		ft_error(0);
	from_array(argc, argv, &stack.a);
	if (!check_sort(stack.a))
		return (0);
	sort(&stack);
	return (0);
}
