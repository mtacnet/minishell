/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 12:42:52 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/18 16:47:36 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_flag_i(t_elem **lst_path, char **tab_arg)
{
	t_elem		*tmp_lst;
	char		**tmp_tab;

	tmp_lst = new_list();
	tmp_tab = NULL;
	if (tab_arg[2] == NULL)
		return ;
	tab_to_list(&tmp_lst, tab_arg);
	supp_elem(&tmp_lst, "env");
	supp_elem(&tmp_lst, "-i");
	tmp_tab = list_to_tab(&tmp_lst);
//	freelst(&tmp_lst);
	recup_param(lst_path, tmp_tab, NULL);
}

void	process_tmp_env(char **tab_arg, t_elem **lst_env, t_elem **lst_path)
{
	t_elem		*cpy_env;
	int			i;
	int			j;

	i = 1;
	j = 0;
	cpy_env = new_list();
	cpy_lst(&cpy_env, lst_env);
	while (tab_arg[i] && tab_arg[i][0] != '\0')
	{
		if (ft_strchr(tab_arg[i], '=') != NULL &&
				verif_list(&cpy_env, tab_arg[i]) == 0)
			push_back(&cpy_env, tab_arg[i]);
		if (ft_strchr(tab_arg[i], '=') == NULL)
			j = i;
		i++;
	}
	if (j == 0)
	{
		view_list(&cpy_env);
		return ;
	}
	else
		process_tmp_bin(tab_arg, cpy_env, lst_path, j);
}
