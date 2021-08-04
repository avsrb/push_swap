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

int	ft_mod(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}



int	nearest_value(t_stack *stack)
{
    t_list *tmp = stack->a;
    int found;
    int found_index = 0;
    int index = 0;

    found = tmp->data; //
	while (tmp)
	{
        if (found > tmp->data && stack->b->data > found) {
            found = tmp->data;
            found_index = index;
        }
        if (tmp->data > stack->b->data && (found < stack->b->data || tmp->data < found))
        {
            found = tmp->data;
            found_index = index;
        }
        index++;
		tmp = tmp->next;
	}
//	printf("found %d\n", found_index);
	return (found_index);
}

//t_list	*nearest_value(t_stack stack)
//{
//	int diff_const;
//	int diff_tmp;
//	t_list *tmp;
//	diff_const = 2147483647;
//	while (stack.a)
//	{
//		if (diff_tmp < 0)
//			diff_tmp = -diff_tmp;
//		diff_tmp = stack.a->data - stack.b->data;
//		if (diff_const > diff_tmp)
//		{
//			diff_const = diff_tmp;
//		}
//		stack.a = stack.a->next;
//	}
//	printf("found %d\n", diff_const);
//	printf("data %d\n", tmp->data);
//}

void	sort_main(t_stack *st)
{
	int	i;
	i = 3;
	int	len = st->size;
	while (i++ < len)
	{
//		if (st->a->data < st->max_a && )
		push(st, 'b');
	}
	sort_three_elem(st, 'a');
	while (st->b)
	{
		while (nearest_value(st))
		{
			rotate(st, 'a');
		}
		push(st, 'a');
	}
    while (check_sort(st->a))
    {
        rotate(st, 'a');
    }



//	nearest_value(st);

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