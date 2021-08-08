#include "./../include/push_swap.h"

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
		write(1, "sa\n", 3);
	}
	else if (name == 'b' && stack->b && stack->b->next)
	{
		swap_action(&stack->b);
		write(1, "sb\n", 3);
	}
	else if (name == 's' && stack->a && stack->a->next
		&& stack->b && stack->b->next)
	{
		swap_action(&stack->a);
		swap_action(&stack->b);
		write(1, "ss\n", 3);
	}
}
