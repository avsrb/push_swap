#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>


typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}			t_stack;


int		validation(int argc, char **argv);
int		skipping(char *str);
int		check_sort(t_list *list);
int		sort(t_stack *stack);

//action
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	push(t_stack *stack, char name);





#endif