#ifndef CHECKER_H
# define CHECKER_H

# include "./../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		len_a;
}			t_stack;

void	swap(t_stack *stack, char name);
void	rotate(t_stack *stack, char name);
void	reverse_rotate(t_stack *stack, char name);
void	push(t_stack *stack, char name);


#endif