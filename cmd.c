/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 12:10:58 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/24 12:47:20 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_cmd(int val, t_elem **lst_env, char **tab_arg, t_elem **lst_path)
{
	if (val != 0)
	{
		if (val == 1 || val == 2 || val == 3)
			process_env(lst_env, val, tab_arg, lst_path);
		if (val == 4)
			process_cd(lst_env, tab_arg);
		if (val == 5)
			process_echo(tab_arg);
		if (val == 6)
			process_exit(lst_env, lst_path, tab_arg);
		return ;
	}
	else
		return ;
}

int		parsing_cmd(char *command)
{
	if (ft_strcmp(command, "env") == 0)
		return (1);
	else if (ft_strcmp(command, "setenv") == 0)
		return (2);
	else if (ft_strcmp(command, "unsetenv") == 0)
		return (3);
	else if (ft_strcmp(command, "cd") == 0)
		return (4);
	else if (ft_strcmp(command, "echo") == 0)
		return (5);
	else if (ft_strcmp(command, "exit") == 0)
		return (6);
	else
		return (0);
}
