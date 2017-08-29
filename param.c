/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:29:13 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/29 17:23:16 by mtacnet          ###   ########.fr       */
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

void			go_bin(t_elem **lst_path, t_elem **lst_env, char **tab_arg)
{
	char	**tmp_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp_env = NULL;
	tmp_env = list_to_tab(lst_env);
	while (tmp_env[i] != '\0')
	{
		if (ft_strncmp(tmp_env[i], "PATH=", 5) == 0)
			j++;
		i++;
	}
	if (j == 0)
		error(2, tab_arg[0], NULL);
	else
		recup_param(lst_path, tab_arg, tmp_env);
	free(tmp_env);
}

static int		process_concat(t_elem **lst_path, char **tab_arg)
{
	char	*swap;

	swap = NULL;
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
	return (check_access((*lst_path)->content));
}

static int		process_path(t_elem **lst_path, char **tab_arg, char **env,
		int i)
{
	int		path_access;

	path_access = 0;
	if (!(ft_strchr(tab_arg[0], '/')))
	{
		path_access = process_concat(lst_path, tab_arg);
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
}
