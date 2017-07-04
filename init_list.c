#include "minishell.h"

t_elem		*new_list(void)
{
	return (NULL);
}

int			is_empty(t_elem *lst)
{
	if (lst == NULL)
		return (1);
	else
		return (0);
}

t_elem		*init_element(t_elem *element)
{
	element = (t_elem*)malloc(sizeof(t_elem));
	if (element == NULL)
	{
		ft_putendl("MEMORY ALLOCATION ERROR");
		exit(EXIT_FAILURE);
	}
	element->name = NULL;
	element->content = NULL;
	element->next = NULL;
	return (element);
}

void		view_list(t_elem *lst)
{
	while (lst != NULL)
	{
		ft_putendl(lst->name);
		ft_putendl(lst->content);
		lst = lst->next;
	}
}

void		freelst(t_elem *lst)
{
	t_elem		*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		free(tmp->name);
		free(tmp->content);
		free(tmp);
		tmp = NULL;
		lst = lst->next;
	}
}
