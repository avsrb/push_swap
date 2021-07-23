#include "../push_swap.h"

void swap(t_list **stack)
{
	if((*stack) || (*stack)->next)
	{
		int tmp;

		tmp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = tmp;
	}
}
