/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:37:08 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/12 14:49:09 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		init_struct_cmd(t_cmd *cmd)
{
	cmd->c_env = 0;
	cmd->c_setenv = 0;
	cmd->c_unset = 0;
	cmd->c_cd = 0;
	cmd->c_echo = 0;
	cmd->c_exit = 0;
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
