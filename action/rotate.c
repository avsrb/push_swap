#include "../push_swap.h"

void	rotate_action(t_list **stack)
{
	if (*stack && (*stack)->next)
	{
		t_list *tmp;

		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
	}
}

void	rotate(t_stack *stack, char name)
{
	if (name == 'a' && stack->a && stack->a->next)
	{
		rotate_action(&stack->a);
		write(1, "ra\n", 3);
	}
	else if (name == 'b'&& stack->b && stack->b->next)
	{
		rotate_action(&stack->b);
		write(1, "rb\n", 3);
	}
	else if (name == 's' && stack->a && stack->a->next
			 && stack->b && stack->b->next)
	{
		rotate_action(&stack->a);
		rotate_action(&stack->b);
		write(1, "rr\n", 3);
	}
}

