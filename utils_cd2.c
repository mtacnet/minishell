/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:56:57 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/23 16:49:58 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_cd2(t_elem **lst_env, char **tab_arg)
{
	int		path_access;
	char	*tmp;

	tmp = go_home(lst_env);
	path_access = 0;
	if ((path_access = check_access(tmp)) == 1)
		change_dir(tmp, lst_env);
	else
		error(1, tab_arg[0], tab_arg[1]);
	ft_strdel(&tmp);
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
