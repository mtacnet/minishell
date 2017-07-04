#include "minishell.h"

t_elem		*push_elem(t_elem *lst, char *name, char *content)
{
	t_elem		*element;
	t_elem		*head;
	t_elem		*prev;

	element = NULL;
	element = init_element(element);
	element->name = ft_strnew(ft_strlen(name));
	element->name = ft_strcpy(element->name, name);
	element->content = ft_strnew(ft_strlen(content));
	element->content = ft_strcpy(element->content, content);
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
