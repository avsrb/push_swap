#include "libft.h"

void	ft_error(char *s)
{
	if(s)
		ft_putstr_fd(s, 2);
	else
		ft_putstr_fd("Error\n", 2);
	exit(1);
}
