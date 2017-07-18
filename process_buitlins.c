/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_buitlins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:18:07 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/18 13:07:08 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		process_f_env(t_elem *lst_env)
{
	view_list(lst_env);
}

static void		process_setenv(t_elem *lst_env, char **tab_arg)
{
	view_list(lst_env);
	ft_putchar('\n');
	//VERIFIER QUE LA VAR PASSEE EN CMD PAR L'USER N'EXISTE PAS, SI ELLE EXISTE
	//ALORS LA MODIFIER A PARTIR DU "="
	view_tab(tab_arg);
}

static void		process_unset(t_elem *lst_env)
{
	view_list(lst_env);
}

void			process_cd(char **env)
{
	view_tab(env);
}

void			process_echo(char **env)
{
	view_tab(env);
}

void			process_exit(char **env)
{
	view_tab(env);
}

void			process_env(char **env, int value, char **tab_arg)
{
	t_elem		*lst_env;

	lst_env = new_list();
	tab_to_list(&lst_env, env);
	if (value == 1)
		process_f_env(lst_env);
	else if (value == 2)
		process_setenv(lst_env, tab_arg);
	else if (value == 3)
		process_unset(lst_env);
}
