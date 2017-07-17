/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:30:47 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/12 14:49:05 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_elem		*push_back(t_elem *lst, char *name, char *content)
{
	t_elem		*element;
	t_elem		*tmp;

	element = NULL;
	element = init_element(element);
	element->name = ft_strdup(name);
	element->content = ft_strdup(content);
	if (is_empty(lst))
		return (element);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (lst);
}
