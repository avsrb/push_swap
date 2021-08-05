#include "push_swap.h"

void	sort_two_elem(t_stack *stack)
{
	if (stack->a->data > stack->a->next->data)
		swap(stack, 'a');
}

void	sort_three_elem(t_stack *s, char name)
{
	if (name == 'a')
	{
		if ((s->a->data > s->a->next->data && s->a->data < s->a->next->next->data)
			|| (s->a->data > s->a->next->data && s->a->data > s->a->next->next->data &&
				s->a->next->data > s->a->next->next->data)
			|| (s->a->data < s->a->next->data && s->a->data < s->a->next->next->data &&
				s->a->next->data > s->a->next->next->data))
			swap(s, 'a');
		if (s->a->next->next->data < s->a->data && s->a->data < s->a->next->data)
			reverse_rotate(s, 'a');
		if (s->a->data > s->a->next->data && s->a->next->data < s->a->next->next->data)
			rotate(s, 'a');
	}
	else if (name == 'b')
	{
		if ((s->b->data > s->b->next->data && s->b->data < s->b->next->next->data)
			|| (s->b->data > s->b->next->data && s->b->data > s->b->next->next->data &&
				s->b->next->data > s->b->next->next->data)
			|| (s->b->data < s->b->next->data && s->b->data < s->b->next->next->data &&
				s->b->next->data > s->b->next->next->data))
			swap(s, 'b');
		if (s->b->next->next->data < s->b->data && s->b->data < s->b->next->data)
			reverse_rotate(s, 'b');
		if (s->b->data > s->b->next->data && s->b->next->data < s->b->next->next->data)
			rotate(s, 'b');
	}
	return ;
}

int	nearest_value(t_stack *stack)
{
	t_list	*tmp = stack->a;
	int	found;
	int	found_index;
	int	index;

	index = 0;
	found_index = 0;
	found = tmp->data;
	while (tmp)
	{
		if ((found > tmp->data && found < stack->b->data)
			|| (tmp->data > stack->b->data && (found < stack->b->data || found > tmp->data)))
		{
			found = tmp->data;
			found_index = index;
		}
		index++;
		tmp = tmp->next;
	}
	return (found_index);
}

void	sort_main(t_stack *st)
{
	int	i;

	i = 3;
	while (i++ < st->len_a)
	{
//		if (st->a->data < st->max_a && )
		push(st, 'b');
	}
	sort_three_elem(st, 'a');
	while (st->b)
	{
		while (nearest_value(st))
		{
			if (nearest_value(st) < (ft_lstsize(st->a)/2))
				rotate(st, 'a');
			else
				reverse_rotate(st, 'a');
		}
		push(st, 'a');
	}
	while (check_sort(st->a))
	{
		if (st->a->data > (ft_lstsize(st->a)/2))
			rotate(st, 'a');
		else
			reverse_rotate(st, 'a');
	}
	return ;
}

int		sort(t_stack *stack)
{
	stack->len_a = ft_lstsize(stack->a);
	if (stack->len_a == 2)
		sort_two_elem(stack);
	if (stack->len_a == 3)
		sort_three_elem(stack, 'a');
	if (stack->len_a > 4)
		sort_main(stack);

	return (0);
}
