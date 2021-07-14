#include "push_swap.h"

int skipping(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		ft_error("Not enough arguments\n");
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '+' || str[i] == '-')
			i++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	validation(int argc, char **argv)
{
	while (*(++argv))
	{
		return(skipping(*argv));
	}
	return (0);
}
