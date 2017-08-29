/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:09:24 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/29 14:34:56 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		verif_list(t_elem **lst, char *tab_arg)
{
	int			i;
	int			len;
	t_elem		*head;

	i = 0;
	len = 0;
	head = (*lst);
	while ((*lst) != NULL)
	{
		i = -1;
		while ((*lst)->content[++i])
			if ((*lst)->content[i] == '=')
				len = i;
		if (ft_strncmp((*lst)->content, tab_arg, len) == 0)
		{
			ft_strdel(&(*lst)->content);
			(*lst)->content = ft_strdup(tab_arg);
			(*lst) = head;
			return (1);
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
	return (0);
}

void	view_list(t_elem **lst)
{
	t_elem		*head;

	head = (*lst);
	while ((*lst) != NULL)
	{
		ft_putendl((*lst)->content);
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
}

int		verif_line(char *line)
{
	int		i;

	i = 0;
	if (line == NULL && !line[0])
		return (1);
	return (0);
}

void	modif_line(char **line)
{
	int		i;

	i = 0;
	while (line[0][i])
	{
		if (line[0][i] == '\t')
			line[0][i] = 040;
		i++;
	}
}

void	cpy_lst(t_elem **lst_dest, t_elem **lst_src)
{
	t_elem		*head;

	head = (*lst_src);
	while ((*lst_src) != NULL)
	{
		push_elem(lst_dest, (*lst_src)->content);
		(*lst_src) = (*lst_src)->next;
	}
	(*lst_src) = head;
}
