#include "minishell.h"

t_elem		*push_elem(t_elem *lst, char *name, char *content)
{
	t_elem		*element;
	t_elem		*head;
	t_elem		*prev;

	element = NULL;
	element = init_element(element);
	element->name = ft_strdup(name);
	element->content = ft_strdup(content);
	head = lst;
	prev = NULL;
	if (is_empty(lst))
		return (element);
	while (lst != NULL)
	{
		prev = lst;
		lst = lst->next;
	}
	if (prev)
		prev->next = element;
	else
		head = element;
	element->next = lst;
	return (head);
}
