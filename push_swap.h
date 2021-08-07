#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	total;
	int	mode;
}			t_moves;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	t_moves	moves;
	int		len_a;
}			t_stack;

int		validation(int argc, char **argv);
void	from_array(int argc, char **argv, t_list **a);
int		skipping(char *str);
int		check_sort(t_list *list);
int		sort(t_stack *stack);

void	swap(t_stack *stack, char name);
void	rotate(t_stack *stack, char name);
void	reverse_rotate(t_stack *stack, char name);
void	push(t_stack *stack, char name);
void	moves_rotate(t_stack *st);
void	moves_reverse_rotate(t_stack *st);
void	moves_ra_and_rrb(t_stack *st);
void	moves_rb_and_rra(t_stack *st);

void	find_best_action(t_stack *st);


#endif