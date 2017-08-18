/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:12:48 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/18 12:19:48 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_elem		*new_list(void)
{
	return (NULL);
}

int			is_empty(t_elem **lst)
{
	if ((*lst) == NULL)
		return (1);
	else
		return (0);
}

t_elem		*init_element(t_elem *element)
{
	if (!(element = (t_elem*)malloc(sizeof(t_elem))))
	{
		ft_putendl("MEMORY ALLOCATION ERROR");
		exit(EXIT_FAILURE);
	}
	element->content = NULL;
	element->next = NULL;
	return (element);
}

void		freelst(t_elem **lst)
{
	t_elem		*list;
	t_elem		*tmp;

	list = (*lst);
	while (list)
	{
		tmp = list;
		ft_strdel(&(list->content));
		free(list);
		list = tmp->next;
	}
	(*lst) = NULL;
}
