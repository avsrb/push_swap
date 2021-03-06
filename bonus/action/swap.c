#include "./../checker.h"

void	swap_action(t_list **stack)
{
	int	tmp;

	if ((*stack) || (*stack)->next)
	{
		tmp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = tmp;
	}
}

void	swap(t_stack *stack, char name)
{
	if (name == 'a' && stack->a && stack->a->next)
	{
		swap_action(&stack->a);
	}
	else if (name == 'b' && stack->b && stack->b->next)
	{
		swap_action(&stack->b);
	}
	else if (name == 's' && stack->a && stack->a->next
		&& stack->b && stack->b->next)
	{
		swap_action(&stack->a);
		swap_action(&stack->b);
	}
}
