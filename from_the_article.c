#include "push_swap.h"

///void	push(t_list **head, int data)
//{
//	t_list	*tmp;
//
//	tmp = malloc(sizeof(*tmp));
//	tmp->data = data;
//	tmp->next = *head;
//	*head = tmp;
//}

int pop(t_list **head)
{
	t_list *prev;
	int	val;

	prev = NULL;
	if (head == NULL)
		ft_error(0);
	prev = (*head);
	val = prev->data;
	(*head) = (*head)->next;
	free (prev);
	return val;
}

t_list	*get_n(t_list *head, int n)
{
	int	counter;

	counter = 0;
	while (counter < n && head)
	{
		head = head->next;
		counter++;
	}
	return (head);
}

t_list	*get_last(t_list *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void push_back(t_list *head, int value)
{
	t_list *last;
	t_list *tmp;

	last = get_last(head);
	tmp = malloc(sizeof(t_list));
	tmp->data = value;
	tmp->next = NULL;
	last->next = tmp;
}

t_list	*get_last_but_one(t_list *head)
{
	if (head == NULL)
		ft_error(0);
	if (head->next == NULL)
		return (NULL);
	while (head->next->next)
		head = head->next;
	return (head);
}

int	pop_back(t_list **head)
{
	t_list	*p_fwd; //Текущий узел
	t_list *p_bwd; //предыдущий узел
	p_fwd = NULL;
	p_bwd = NULL;

	if (!head)
		ft_error(0);
	if (!(*head))
		ft_error(0);
	p_fwd = *head;
	while (p_fwd->next)
	{
		p_bwd = p_fwd;
		p_fwd = p_fwd->next;
	}
	if (p_bwd == NULL)
	{
		free (*head);
		*head = NULL;
	}
	else
	{
		free(p_fwd->next);
		p_bwd->next = NULL;
	}
	return (0);
}

void insert (t_list *head, unsigned n, int val)
{
	unsigned int i;
	t_list		*tmp;

	i = 0;
	tmp = NULL;

	while (i < n && head->next)
	{
		head = head->next;
		i++;
	}
	tmp = malloc(sizeof(t_list));
	tmp->data = val;
	if (head->next)
		tmp->next = head->next;
	else
		head->next = NULL;
	head->next = tmp;
}

int	del_n(t_list **head, int n)
{
	if (n == 0)
		return pop (head);
	else
	{
		t_list *prev;
		t_list *elm;
		int val;

		prev = get_n(*head, n - 1);
		elm = prev->next;
		val = elm->data;
		prev->next = elm->next;
		free(elm);
		return (val);
	}
}

void	delete_list(t_list **head)
{
	t_list *prev;

	prev = NULL;
	while ((*head)->next)
	{
		prev = (*head);
		(*head) = (*head)->next;
	}
	free(*head);
}
int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}