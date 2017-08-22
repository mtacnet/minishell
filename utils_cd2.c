/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:56:57 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/19 15:05:56 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_cd2(t_elem **lst_env, char **tab_arg)
{
	int		path_access;

	path_access = 0;
	if ((path_access = check_access(go_home(lst_env))) == 1)
		change_dir(go_home(lst_env), lst_env);
	else
		error(1, tab_arg[0], tab_arg[1]);
}

void	go_path(t_elem **lst_env, char **tab)
{
	int		path_access;

	path_access = 0;
	if (check_old_pwd(lst_env) == 0)
		add_old_pwd(lst_env);
	if ((path_access = check_access(tab[1])) == 1)
		change_dir(tab[1], lst_env);
	else
		error(1, tab[0], tab[1]);
}
