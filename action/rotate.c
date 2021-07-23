#include "../push_swap.h"

void	rotate(t_list **stack)
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

