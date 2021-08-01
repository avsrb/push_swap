#include "push_swap.h"

void	sort_three_elem(t_stack *stack)
{
	t_list	*sec;

	sec = stack->a->next;
	if (stack->a->data > stack->a->next->data && stack->a->data > stack->a->next->next->data ||\
		stack->a->data < stack->a->next->data && stack->a->data > stack->a->next->next->data ||\
		stack->a->data > stack->a->next->data && stack->a->data < stack->a->next->next->data)
		swap(stack, 'a');
	if (stack->a->data > stack->a->next->data && stack->a->data > stack->a->next->next->data)
		rotate()
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