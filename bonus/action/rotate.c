#include "./../checker.h"

void	rotate_action(t_list **stack)
{
	t_list	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
	}
}

void	rotate(t_stack *stack, char name)
{
	if (name == 'a')
	{
		rotate_action(&stack->a);
	}
	else if (name == 'b')
	{
		rotate_action(&stack->b);
	}
	else if (name == 's')
	{
		rotate_action(&stack->a);
		rotate_action(&stack->b);
	}
}
