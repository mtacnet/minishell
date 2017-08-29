/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:36:54 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/29 14:02:12 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		cd_error2(char *bad_cmd)
{
	ft_putstr_fd(bad_cmd, 2);
	ft_putstr_fd(": HOME not set\n", 2);
}

static void		cd_error(char *bad_cmd)
{
	ft_putstr_fd(bad_cmd, 2);
	ft_putstr_fd(": OLDPWD not set\n", 2);
}

static void		error_cmd(char *bad_cmd)
{
	if (ft_strncmp(bad_cmd, "-i", 2) == 0)
		return ;
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putstr_fd(bad_cmd, 2);
	ft_putstr_fd("\n", 2);
}

static void		view_error(char *bad_cmd, char *bad_flag)
{
	ft_putstr_fd(bad_cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("no such file or directory: ", 2);
	ft_putstr_fd(bad_flag, 2);
	ft_putstr_fd("\n", 2);
}

void			error(int value, char *bad_cmd, char *bad_flag)
{
	if (value == 1)
		view_error(bad_cmd, bad_flag);
	if (value == 2)
		error_cmd(bad_cmd);
	if (value == 3)
		cd_error(bad_cmd);
	if (value == 4)
		cd_error2(bad_cmd);
	if (value == 5)
		env_error(bad_cmd, bad_flag);
}
