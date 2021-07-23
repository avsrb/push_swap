#include "../push_swap.h"

void	push(t_stack *stack, char name) {
	t_list *tmp;

	if (name == 'b')
	{
		if(stack->a)
		{
			tmp = stack->a;
			stack->a = stack->a->next;
			tmp->next = NULL;
			ft_lstadd_front(&stack->b, tmp);
		}
	}
	else if (name == 'a')
	{
		if (stack->b)
		{
			stack->b = stack->b->next;
			stack->b = tmp->next;
			tmp->next = NULL;
			ft_lstadd_front(&stack->a, tmp);
		}
	}
	tmp = NULL;
}
