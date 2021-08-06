#include "push_swap.h"


void	st_print(t_list *st_a, t_list *st_b)
{
	t_list *tmp_a = st_a;
	t_list *tmp_b = st_b;

	while (tmp_a || tmp_b)
	{
		printf("data_a ");
		if (tmp_a)
			printf("%d", tmp_a->data);
		printf("   ");
		printf("data_b ");
		if (tmp_b)
			printf("%d", tmp_b->data);
		printf("\n");
		if(tmp_a)
			tmp_a = tmp_a->next;
		if (tmp_b)
			tmp_b = tmp_b->next;
	}
}
