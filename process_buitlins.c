/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_buitlins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:18:07 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/20 11:39:28 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		process_f_env(t_elem *lst_env)
{
	view_list(lst_env);
}

static void		process_setenv(t_elem *lst_env, char **tab_arg)
{
	int		i;

	i = 1;
	while (tab_arg[i] && tab_arg[i][0] != '\0')
	{
		if (verif_tab(tab_arg[i]) == 1)
			tab_arg[i] = ft_strjoin(tab_arg[i], "=");
		if (verif_list(lst_env, tab_arg[i]) == 0)
			lst_env = push_back(lst_env, "ENV", tab_arg[i]);
		i++;
	}
}

static void		process_unset(t_elem *lst_env, char **tab_arg)
{
	int		i;

	i = 1;
	while (tab_arg[i] && tab_arg[i][0] != '\0')
	{
		if (modif_list(lst_env, tab_arg[i]) == 1)
			lst_env = supp_elem(lst_env, tab_arg[i]);
		i++;
	}
}

void			process_cd(t_elem *lst_env)
{
	view_list(lst_env);
}

void			process_echo(t_elem *lst_env)
{
	view_list(lst_env);
}

void			process_exit(t_elem *lst_env)
{
	view_list(lst_env);
}

void			process_env(t_elem *lst_env, int value, char **tab_arg)
{
	if (value == 1)
		process_f_env(lst_env);
	else if (value == 2)
		process_setenv(lst_env, tab_arg);
	else if (value == 3)
		process_unset(lst_env, tab_arg);
}
