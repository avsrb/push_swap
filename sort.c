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

int	nearest_value_optional(t_list *st_a, t_list *st_b)
{
	t_list	*tmp = st_a;
	int	found;
	int	found_index;
	int	index;

	index = 0;
	found_index = 0;
	found = tmp->data;
	while (tmp)
	{
		if ((found > tmp->data && found < st_b->data)
			|| (tmp->data > st_b->data && (st_b->data > found || tmp->data < found)))
		{
			found = tmp->data;
			found_index = index;
		}
		index++;
		tmp = tmp->next;
	}
	return (found_index);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_choise_best_way(t_moves *tmp_moves)
{
	tmp_moves->total = INT_MAX;

	if (ft_max(tmp_moves->ra, tmp_moves->rb) < tmp_moves->total) //
	{
		tmp_moves->total = ft_max(tmp_moves->ra, tmp_moves->rb);
		tmp_moves->mode = 1;
	}
	if (ft_max(tmp_moves->rra, tmp_moves->rrb) < tmp_moves->total) //
	{
		tmp_moves->total = ft_max(tmp_moves->rra, tmp_moves->rrb);
		tmp_moves->mode = 2;
	}
	if (tmp_moves->ra + tmp_moves->rrb < tmp_moves->total) //
	{
		tmp_moves->total = tmp_moves->ra + tmp_moves->rrb;
		tmp_moves->mode = 3;
	}
	if (tmp_moves->rra + tmp_moves->rb < tmp_moves->total) //
	{
		tmp_moves->total = tmp_moves->rra + tmp_moves->rb;
		tmp_moves->mode = 4;
	}
}

void	find_best_action(t_stack *st)
{
	t_list 	*tmp_b;
	t_list 	*tmp_b_start;
	t_moves	tmp_moves;

	int index = 0;
	st->moves.total = INT_MAX;

	tmp_b = st->b;
	tmp_b_start = st->b;

	//st_print(st->a, tmp_b_start);
	while (tmp_b)
	{
		tmp_moves.ra = nearest_value_optional(st->a, tmp_b);
		tmp_moves.rb = index;
		tmp_moves.rra = ft_lstsize(st->a) - tmp_moves.ra;
		tmp_moves.rrb = ft_lstsize(tmp_b_start) - tmp_moves.rb;
		ft_choise_best_way(&tmp_moves);
		//printf("\tstep\t%d\tindex \t%d\n", step, index);
		if (tmp_moves.total < st->moves.total)
		{
			st->moves.ra = tmp_moves.ra;
			st->moves.rb = tmp_moves.rb;
			st->moves.rra = tmp_moves.rra;
			st->moves.rrb = tmp_moves.rrb;
			st->moves.total = tmp_moves.total;
			st->moves.mode = tmp_moves.mode;
		}
		index++;
		tmp_b = tmp_b->next;
	}
}

void	sort_main(t_stack *st)
{
	int	i;

	i = 3;
	while (i++ < st->len_a)
	{
		push(st, 'b');
	}
	sort_three_elem(st, 'a');

	while (st->b)
	{
		find_best_action(st);
		if (st->moves.mode == 1)
		{
			while (st->moves.ra && st->moves.rb) // > 0
			{
				rotate(st, 's');
				st->moves.ra--;
				st->moves.rb--;
			}
			while (st->moves.ra) // > 0
			{
				rotate(st, 'a');
				st->moves.ra--;
			}
			while (st->moves.rb) // > 0
			{
				rotate(st, 'b');
				st->moves.rb--;
			}
		}
		if (st->moves.mode == 2)
		{
			while (st->moves.rra && st->moves.rrb) // > 0
			{
				reverse_rotate(st, 's');
				st->moves.rra--;
				st->moves.rrb--;
			}
			while (st->moves.rra) // > 0
			{
				reverse_rotate(st, 'a');
				st->moves.rra--;
			}
			while (st->moves.rrb) // > 0
			{
				reverse_rotate(st, 'b');
				st->moves.rrb--;
			}
		}
		if (st->moves.mode == 3)
		{
			while (st->moves.ra) // > 0
			{
				rotate(st, 'a');
				st->moves.ra--;
			}
			while (st->moves.rrb) // > 0
			{
				reverse_rotate(st, 'b');
				st->moves.rrb--;
			}
		}
		if (st->moves.mode == 4)
		{
			while (st->moves.rb) // > 0
			{
				rotate(st, 'b');
				st->moves.rb--;
			}
			while (st->moves.rra) // > 0
			{
				reverse_rotate(st, 'a');
				st->moves.rra--;
			}
		}
		push(st, 'a');
	}

	while (check_sort(st->a))
	{
		if (st->a->data <= ft_lstsize(st->a))
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
