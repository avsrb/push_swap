#include "push_swap.h"

void	sort_two_elem(t_stack *stack)
{
	if (stack->a->data > stack->a->next->data)
		swap(stack, 'a');
}

void	sort_three_elem(t_stack *stack, char name)
{
	if (name == 'a')
	{
		if ((stack->a->data > stack->a->next->data && stack->a->data < stack->a->next->next->data)
			|| (stack->a->data > stack->a->next->data && stack->a->data > stack->a->next->next->data &&
				stack->a->next->data > stack->a->next->next->data)
			|| (stack->a->data < stack->a->next->data && stack->a->data < stack->a->next->next->data &&
				stack->a->next->data > stack->a->next->next->data))
			swap(stack, 'a');
		if (stack->a->next->next->data < stack->a->data && stack->a->data < stack->a->next->data)
			reverse_rotate(stack, 'a');
		if (stack->a->data > stack->a->next->data && stack->a->next->data < stack->a->next->next->data)
			rotate(stack, 'a');
	}
	else if (name == 'b')
	{
		if ((stack->b->data > stack->b->next->data && stack->b->data < stack->b->next->next->data)
			|| (stack->b->data > stack->b->next->data && stack->b->data > stack->b->next->next->data &&
				stack->b->next->data > stack->b->next->next->data)
			|| (stack->b->data < stack->b->next->data && stack->b->data < stack->b->next->next->data &&
				stack->b->next->data > stack->b->next->next->data))
			swap(stack, 'b');
		if (stack->b->next->next->data < stack->b->data && stack->b->data < stack->b->next->data)
			reverse_rotate(stack, 'b');
		if (stack->b->data > stack->b->next->data && stack->b->next->data < stack->b->next->next->data)
			rotate(stack, 'b');
	}
	return ;
}

void	sort_main(t_stack *stack)
{
	int	i;
	i = 3;

	while (stack->size >= ++i)
		push(stack, 'b');
	sort_three_elem(stack, 'a');
	stack->max_a = ft_lstlast(stack->a);
	if (stack->b->data > stack->max_a)
		push (stack, 'b');

	return ;
}





int		sort(t_stack *stack)
{
	stack->size = ft_lstsize(stack->a);
	if (stack->size == 2)
		sort_two_elem(stack);
	if (stack->size == 3)
		sort_three_elem(stack, 'a');
	if (stack->size > 5)
		sort_main(stack);


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