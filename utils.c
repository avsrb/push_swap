#include "push_swap.h"

int	nearest_value_optional(t_list *st_a, t_list *st_b)
{
	t_list	*tmp;
	int		found;
	int		found_index;
	int		index;

	tmp = st_a;
	index = 0;
	found_index = 0;
	found = tmp->data;
	while (tmp)
	{
		if ((found > tmp->data && found < st_b->data) || \
			(tmp->data > st_b->data && (st_b->data > found || \
										tmp->data < found)))
		{
			found = tmp->data;
			found_index = index;
		}
		index++;
		tmp = tmp->next;
	}
	return (found_index);
}

void	ft_choise_best_way(t_moves *tmp_moves)
{
	tmp_moves->total = INT_MAX;
	if (ft_max(tmp_moves->ra, tmp_moves->rb) < tmp_moves->total)
	{
		tmp_moves->total = ft_max(tmp_moves->ra, tmp_moves->rb);
		tmp_moves->mode = 1;
	}
	if (ft_max(tmp_moves->rra, tmp_moves->rrb) < tmp_moves->total)
	{
		tmp_moves->total = ft_max(tmp_moves->rra, tmp_moves->rrb);
		tmp_moves->mode = 2;
	}
	if (tmp_moves->ra + tmp_moves->rrb < tmp_moves->total)
	{
		tmp_moves->total = tmp_moves->ra + tmp_moves->rrb;
		tmp_moves->mode = 3;
	}
	if (tmp_moves->rra + tmp_moves->rb < tmp_moves->total)
	{
		tmp_moves->total = tmp_moves->rra + tmp_moves->rb;
		tmp_moves->mode = 4;
	}
}

void	ft_equate(t_stack *st, t_moves *tmp_moves)
{
	st->moves.ra = tmp_moves->ra;
	st->moves.rb = tmp_moves->rb;
	st->moves.rra = tmp_moves->rra;
	st->moves.rrb = tmp_moves->rrb;
	st->moves.total = tmp_moves->total;
	st->moves.mode = tmp_moves->mode;
}

void	find_best_action(t_stack *st)
{
	t_list		*tmp_b;
	t_list		*tmp_b_start;
	t_moves		tmp_moves;
	int			index;

	index = 0;
	st->moves.total = INT_MAX;
	tmp_b = st->b;
	tmp_b_start = st->b;
	while (tmp_b)
	{
		tmp_moves.ra = nearest_value_optional(st->a, tmp_b);
		tmp_moves.rb = index;
		tmp_moves.rra = ft_lstsize(st->a) - tmp_moves.ra;
		tmp_moves.rrb = ft_lstsize(tmp_b_start) - tmp_moves.rb;
		ft_choise_best_way(&tmp_moves);
		if (tmp_moves.total < st->moves.total)
			ft_equate(st, &tmp_moves);
		index++;
		tmp_b = tmp_b->next;
	}
}
