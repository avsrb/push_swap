#include "push_swap.h"

int	validation(int argc, char **argv)
{
	while (*(++argv))
	{
		skipping(*argv);
	}
	return(1);
}

void skipping(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '+' || str[i] == '-')
			i++;
		else
			ft_error();
	}
}
