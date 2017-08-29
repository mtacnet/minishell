/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 13:49:56 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/29 14:00:57 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_error(char *bad_cmd, char *bad_flag)
{
	ft_putstr_fd(bad_cmd, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putstr_fd(bad_flag, 2);
	ft_putstr_fd("\nusage: env [-i] [utility]\n", 2);
}
