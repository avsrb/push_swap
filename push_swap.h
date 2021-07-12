#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct stack_a	*next;
}			t_stack;

int		validation(int argc, char **argv);
void	ft_error(void);
void		skipping(char *str);
void 	digit(char *str);
int	ft_atoi(const char *str);


#endif