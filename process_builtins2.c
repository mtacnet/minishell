/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_builtins2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:08:46 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/29 14:27:12 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			process_echo(char **tab)
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

static void		process_tild(t_elem **lst_env, char *tmp)
{
	int		path_access;

	path_access = 0;
	if (check_old_pwd(lst_env) == 0)
		add_old_pwd(lst_env);
	if ((path_access = check_access(tmp)) == 1)
		change_dir(tmp, lst_env);
	else
		error(4, "cd", NULL);
}

void			process_cd(t_elem **lst_env, char **tab_arg)
{
	char	*tmp;
	char	*tmp2;

	tmp = go_home(lst_env);
	tmp2 = go_old_pwd(lst_env);
	if (tab_arg[1] != NULL)
	{
		if (tab_arg[1][0] == '~')
			process_tild(lst_env, tmp);
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
		process_cd2(lst_env);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}
