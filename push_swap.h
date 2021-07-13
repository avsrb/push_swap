#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_params
{
	t_list	*a;
	t_list	*b;
}			t_params;


int		validation(int argc, char **argv);
void	ft_error(void);
void	skipping(char *str);
void 	digit(char *str);


#endif