#include "./../include/push_swap.h"

void	sort_two_elem(t_stack *stack)
{
	if (stack->a->data > stack->a->next->data)
		swap(stack, 'a');
}

void	sort_three_elem(t_stack *s)
{
	if ((s->a->data > s->a->next->data && s->a->data < s->a->next->next->data) || \
		(s->a->data > s->a->next->data && s->a->data > s->a->next->next->data && \
		 s->a->next->data > s->a->next->next->data) || \
		(s->a->data < s->a->next->data && s->a->data < s->a->next->next->data && \
		 s->a->next->data > s->a->next->next->data))
		swap(s, 'a');
	if (s->a->next->next->data < s->a->data && s->a->data < s->a->next->data)
		reverse_rotate(s, 'a');
	if (s->a->data > s->a->next->data &&\
		s->a->next->data < s->a->next->next->data)
		rotate(s, 'a');
	return ;
}

void	ft_choise_mode(t_stack *st)
{
	find_best_action(st);
	if (st->moves.mode == 1)
		moves_rotate(st);
	if (st->moves.mode == 2)
		moves_reverse_rotate(st);
	if (st->moves.mode == 3)
		moves_ra_and_rrb(st);
	if (st->moves.mode == 4)
		moves_rb_and_rra(st);
}

void	sort_main(t_stack *st)
{
	int		med;
	int		med_size;

	med_size = ft_lstsize(st->a) / 2;
	med = (ft_lstfindmax(st->a) - ft_lstfindmin(st->a)) / 2 + 1;
	while (3 != ft_lstsize(st->a))
	{
		if (med < st->a->data && ft_lstsize(st->a) > med_size && med_size > 100)
			rotate(st, 'a');
		else
			push(st, 'b');
	}
	sort_three_elem(st);
	while (st->b)
	{
		ft_choise_mode(st);
		push(st, 'a');
	}
	while (check_sort(st->a))
	{
		if (st->moves.ra <= ft_lstsize(st->a))
			rotate(st, 'a');
		else
			reverse_rotate(st, 'a');
	}
}

int	sort(t_stack *stack)
{
	stack->len_a = ft_lstsize(stack->a);
	if (stack->len_a == 2)
		sort_two_elem(stack);
	if (stack->len_a == 3)
		sort_three_elem(stack);
	if (stack->len_a >= 4)
		sort_main(stack);
	return (0);
}
