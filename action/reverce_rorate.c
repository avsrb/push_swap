#include "../push_swap.h"

void	reverse_rotate(t_list **stack)
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
