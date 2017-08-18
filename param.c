/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:29:13 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/18 16:02:08 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				check_access(char *path)
{
	int		ret_access;

	ret_access = access(path, F_OK);
	if (ret_access == 0)
	{
		if (access(path, X_OK) == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static int		process_path(t_elem **lst_path, char **tab_arg, char **env,
		int i)
{
	int		path_access;
	char	*swap;

	path_access = 0;
	swap = NULL;
	if (!(ft_strchr(tab_arg[0], '/')))
	{
		swap = ft_strdup((*lst_path)->content);
		ft_strdel(&((*lst_path)->content));
		(*lst_path)->content = ft_strnew(ft_strlen(swap) + 1);
		(*lst_path)->content = ft_strcpy((*lst_path)->content, swap);
		(*lst_path)->content = ft_strcat((*lst_path)->content, "/");
		ft_strdel(&(swap));
		swap = ft_strdup((*lst_path)->content);
		ft_strdel(&((*lst_path)->content));
		(*lst_path)->content = ft_strnew(ft_strlen(swap) + ft_strlen(tab_arg[0]));
		(*lst_path)->content = ft_strcpy((*lst_path)->content, swap);
		(*lst_path)->content = ft_strcat((*lst_path)->content, tab_arg[0]);
		ft_strdel(&swap);
		path_access = check_access((*lst_path)->content);
		if (path_access == 1)
		{
			if_path((*lst_path)->content, tab_arg, env);
			return (1);
		}
	}
	else if (i == 0)
	{
		path_access = check_access(tab_arg[0]);
		if (path_access == 1)
		{
			if_path(tab_arg[0], tab_arg, env);
			return (1);
		}
	}
	return (0);
}

void			recup_param(t_elem **lst_path, char **tab_arg, char **env)
{
	int			i;
	int			j;
	int			k;
	t_elem		*head;

	i = 0;
	j = 0;
	k = 0;
	head = (*lst_path);
	while ((*lst_path) != NULL)
	{
		j = process_path(lst_path, tab_arg, env, i);
		if (j == 1)
			k = 1;
		i++;
		(*lst_path) = (*lst_path)->next;
	}
	(*lst_path) = head;
	if (k != 1)
		error(2, tab_arg[0], NULL);
	freelst(lst_path);
}
