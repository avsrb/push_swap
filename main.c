#include "push_swap.h"

void 	from_array(int argc, char **argv, t_list **a)
{
	int i;
	int nbr;

	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv[1] == NULL)
			ft_error(0);
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

int	main(int argc, char **argv)
{
	t_stack stack;

	stack.a = NULL;
	stack.b = NULL;
	if (validation(argc, argv))
		ft_error(0);
	from_array(argc, argv, &stack.a);
	if (!check_sort(stack.a))
		return (0);
	sort(&stack);
//	while (stack.a || stack.b)
//	{
//		printf("data_a ");
//		if (stack.a)
//			printf("%d", stack.a->data);
//		printf("   ");
//		printf("data_b ");
//		if (stack.b)
//			printf("%d", stack.b->data);
//		printf("\n");
//		if(stack.a)
//			stack.a = stack.a->next;
//		if (stack.b)
//			stack.b = stack.b->next;
//	}
	return(0);
}
