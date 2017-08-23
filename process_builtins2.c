/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_builtins2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:08:46 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/23 16:41:07 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_echo(char **tab)
{
	int		i;

	i = 1;
	while (tab[i] && tab[i][0] != '\0')
	{
		ft_putstr(tab[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putchar('\n');
}

void	process_cd(t_elem **lst_env, char **tab_arg)
{
	int		path_access;
	char	*tmp;
	char	*tmp2;

	path_access = 0;
	tmp = go_home(lst_env);
	tmp2 = go_old_pwd(lst_env);
	if (tab_arg[1] != NULL)
	{
		if (tab_arg[1][0] == '~')
		{
			if (check_old_pwd(lst_env) == 0)
				add_old_pwd(lst_env);
			if ((path_access = check_access(tmp)) == 1)
				change_dir(tmp, lst_env);
			else
				error(1, tab_arg[0], tab_arg[1]);
		}
		else if (tab_arg[1][0] == '-')
		{
			if (check_old_pwd(lst_env) != 0)
				change_dir(tmp2, lst_env);
			else
				error(3, "cd", NULL);
		}
		else
			go_path(lst_env, tab_arg);
	}
	else
		process_cd2(lst_env, tab_arg);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}
