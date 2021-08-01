#include "push_swap.h"

void	sort_three_elem(t_stack *stack)
{
	if ((stack->a->data > stack->a->next->data && stack->a->data < stack->a->next->next->data)
		|| (stack->a->data > stack->a->next->data && stack->a->data > stack->a->next->next->data && stack->a->next->data > stack->a->next->next->data)
		|| (stack->a->data < stack->a->next->data && stack->a->data < stack->a->next->next->data && stack->a->next->data > stack->a->next->next->data))
		swap(stack, 'a');
	if (stack->a->next->next->data < stack->a->data && stack->a->data < stack->a->next->data)
		reverse_rotate(stack, 'a');
	if (stack->a->data > stack->a->next->data && stack->a->next->data < stack->a->next->next->data)
		rotate(stack, 'a');
	return ;
}

int		sort(t_stack *stack)
{
	int size = ft_lstsize(stack->a);
	if (size == 3)
		sort_three_elem(stack);


//	push(stack, 'b');
//	swap(stack, 'b');
//	reverse_rotate(stack, 'a');
//	rotate(stack, 'b');




	return (0);
}

//int		swap(t_stack *stack, char name)
//{
//	if (name == 'a')
//	{
//
//
//	}
//}