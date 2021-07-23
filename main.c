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
		ft_lstfind(*a, nbr);
		ft_lstadd_back(a, ft_lstnew(nbr));
		i++;
	}
}

int	check_sort(t_list *list)
{
	while (list->next)
	{
		if (list->data < list->next->data)
			list = list->next;
		else
			return (1);
	}
	return (0);
}

void	indexing(t_list *list)
{
	int	index;

	index = 0;
	while (list->next)
	{
		list->index = index;
		index++;
		list = list->next;
	}
	list->index = index;
}

int	main(int argc, char **argv)
{
	t_stack stack;

	if (validation(argc, argv))
		ft_error(0);
	from_array(argc, argv, &stack.a);
	if (!check_sort(stack.a))
		return (0);
	//indexing (stack.a);
	sort(&stack);
	while (stack.a || stack.b)
	{
//		printf("index %d\n", stack.a->index);
		printf("data_a ");
		if (stack.a)
			printf("%d", stack.a->data);
		printf("   ");
		printf("data_b ");
		if (stack.b)
			printf("%d", stack.b->data);
		printf("\n");
		if(stack.a)
			stack.a = stack.a->next;
		if (stack.b)
			stack.b = stack.b->next;

	}
	return(0);
}
