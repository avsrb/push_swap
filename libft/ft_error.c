#include "libft.h"

void	ft_error(char *s)
{
	if (s)
		ft_putstr_fd(s, 1);
	else
		ft_putstr_fd("Error\n", 1);
	exit(1);
}
