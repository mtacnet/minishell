/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 12:33:28 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/23 13:50:19 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		process_f_env(t_elem **lst_env, char **tab_arg,
		t_elem **lst_path)
{
	char	**tmp_tab;
	int		i;
	int		j;

	tmp_tab = NULL;
	i = 0;
	j = 0;
	if (tab_arg[1] == NULL)
		view_list(lst_env);
	else if (tab_arg[1])
	{
		if (ft_strncmp(tab_arg[1], "-i", 2) == 0)
			process_flag_i(lst_path, tab_arg);
		else if (ft_strchr(tab_arg[1], '=') != NULL)
			process_tmp_env(tab_arg, lst_env, lst_path);
		else
			process_bin(tab_arg, lst_env, lst_path);
	}
}

void			process_setenv(t_elem **lst_env, char **tab_arg)
{
	int		i;

	i = 1;
	while (tab_arg[i] && tab_arg[i][0] != '\0')
	{
		if (verif_tab(tab_arg[i]) == 1)
			tab_arg[i] = ft_strcat(tab_arg[i], "=");
		if (verif_list(lst_env, tab_arg[i]) == 0)
			push_back(lst_env, tab_arg[i]);
		i++;
	}
}

void		process_unset(t_elem **lst_env, char **tab_arg)
{
	int		i;

	i = 1;
	while (tab_arg[i] && tab_arg[i][0] != '\0')
	{
		if (modif_list(lst_env, tab_arg[i]) == 1)
		{
			supp_elem(lst_env, tab_arg[i]);`
		}
		i++;
	}
}

void			process_exit(t_elem **lst_env, t_elem **lst_path,
		char **tab_arg)
{
	freelst(lst_env);
	freelst(lst_path);
	free_tab(tab_arg);
	tab_arg = NULL;
	if (tab_arg != NULL)
	{
		ft_putendl("ERROR MEMORY FREE");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void			process_env(t_elem **lst_env, int val, char **tab_arg,
		t_elem **lst_path)
{
	if (val == 1)
		process_f_env(lst_env, tab_arg, lst_path);
	else if (val == 2)
		process_setenv(lst_env, tab_arg);
	else if (val == 3)
		process_unset(lst_env, tab_arg);
}
