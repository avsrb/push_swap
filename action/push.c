#include "./../include/push_swap.h"

void	push(t_stack *stack, char name)
{
	t_list	*tmp;

	tmp = NULL;
	if (name == 'b' && stack->a)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
		tmp->next = NULL;
		ft_lstadd_front(&stack->b, tmp);
		write(1, "pb\n", 3);
	}
	else if (name == 'a' && stack->b)
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		tmp->next = NULL;
		ft_lstadd_front(&stack->a, tmp);
		write(1, "pa\n", 3);
	}
}
