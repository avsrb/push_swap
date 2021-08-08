#include "./../include/push_swap.h"

void	rotate_action(t_list **stack)
{
	t_list	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
	}
}

void	rotate(t_stack *stack, char name)
{
	if (name == 'a')
	{
		rotate_action(&stack->a);
		write(1, "ra\n", 3);
	}
	else if (name == 'b')
	{
		rotate_action(&stack->b);
		write(1, "rb\n", 3);
	}
	else if (name == 's')
	{
		rotate_action(&stack->a);
		rotate_action(&stack->b);
		write(1, "rr\n", 3);
	}
}

void	moves_rotate(t_stack *st)
{
	while (st->moves.ra && st->moves.rb)
	{
		rotate(st, 's');
		st->moves.ra--;
		st->moves.rb--;
	}
	while (st->moves.ra)
	{
		rotate(st, 'a');
		st->moves.ra--;
	}
	while (st->moves.rb)
	{
		rotate(st, 'b');
		st->moves.rb--;
	}
}

void	moves_ra_and_rrb(t_stack *st)
{
	while (st->moves.ra)
	{
		rotate(st, 'a');
		st->moves.ra--;
	}
	while (st->moves.rrb)
	{
		reverse_rotate(st, 'b');
		st->moves.rrb--;
	}
}

void	moves_rb_and_rra(t_stack *st)
{
	while (st->moves.rb)
	{
		rotate(st, 'b');
		st->moves.rb--;
	}
	while (st->moves.rra)
	{
		reverse_rotate(st, 'a');
		st->moves.rra--;
	}
}
