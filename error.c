/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:36:54 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/21 13:55:57 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		error_flag(char *bad_cmd, char *bad_flag)
{
	ft_putstr_fd(bad_cmd, 2);
	ft_putstr_fd(": ", 2);
	if (bad_flag[0] == '-')
	{
		ft_putstr_fd("illegal option -- ", 2);
		ft_putchar_fd(bad_flag[1], 2);
		ft_putstr_fd("\nusage: env [-i] [name=value ...] [cmd]", 2);
	}
	else
	{
		ft_putstr_fd(bad_flag, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("No such file or directory", 2);
	}
	ft_putstr_fd("\n", 2);
}

void			error(int value, char *bad_cmd, char *bad_flag)
{
	if (value == 1)
		error_flag(bad_cmd, bad_flag);
}
