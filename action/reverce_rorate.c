#include "../push_swap.h"

void	reverse_rotate_action(t_list **stack)
{
	if (*stack && (*stack)->next)
	{
		t_list *tmp;
		t_list *tmp1;

		tmp1 = (*stack);
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp = tmp1->next;
		tmp1->next = NULL;
		ft_lstadd_front(stack, tmp);
	}
}

void	reverse_rotate(t_stack *stack, char name)
{
	if (name == 'a' && stack->a && stack->a->next)
	{
		reverse_rotate_action(&stack->a);
		write(1, "rra\n", 4);
	}
	else if (name == 'b'&& stack->b && stack->b->next)
	{
		reverse_rotate_action(&stack->b);
		write(1, "rrb\n", 4);
	}
	else if (name == 's' && stack->a && stack->a->next
			 && stack->b && stack->b->next)
	{
		reverse_rotate_action(&stack->a);
		reverse_rotate_action(&stack->b);
		write(1, "rrr\n", 3);
	}
}
