#include "./../checker.h"

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
	}
	else if (name == 'a' && stack->b)
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		tmp->next = NULL;
		ft_lstadd_front(&stack->a, tmp);
	}
}
