/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:30:47 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/20 11:38:14 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		tab_to_list(t_elem **lst_env, char **env)
{
	int		i;

	i = 0;
	while (env[i] && env[i][0] != '\0')
	{
		*lst_env = push_elem(*lst_env, "ENV", env[i]);
		i++;
	}
}

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

t_elem		*supp_elem(t_elem *lst, char *arg)
{
	size_t		i;
	t_elem		*tmp;
	t_elem		*prev;

	i = 0;
	tmp = lst;
	prev = NULL;
	while (arg[i] != '\0')
		i++;
	if (tmp != NULL && ft_strncmp(tmp->content, arg, i) == 0)
	{
		lst = tmp->next;
		free(tmp);
		return (NULL);
	}
	while (tmp != NULL && ft_strncmp(tmp->content, arg, i) != 0)
	{
		 prev = tmp;
		 tmp = tmp->next;
	}
	if (tmp == NULL)
		return (NULL);;
	prev->next = tmp->next;
	free(tmp);
	return (lst);
 }
