/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:36:58 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/12 17:15:09 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** save_arg: Enregistre le contenu du tableau dans la liste "lst_arg" passée
** en paramètre.
*/

void	save_arg(char **tab_arg, t_elem **lst_arg)
{
	int		i;

	i = 0;
	while (tab_arg[i] && tab_arg[i][0] != '\0')
	{
		*lst_arg = push_elem(*lst_arg, "CMD", tab_arg[i]);
		i++;
	}
}

/*
** view_list: Affiche le contenu des éléments de la liste
*/

void	view_list(t_elem *lst)
{
	while (lst != NULL)
	{
		ft_putendl(lst->content);
		lst = lst->next;
	}
}

/*
** view_tab: Affiche le contenu du tableau passé en paramètre.
*/

void	view_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] && tab[i][0] != '\0')
	{
		ft_putendl(tab[i]);
		i++;
	}
}

/*
** check_cmd: Si la value checkée est a 1 alors redirection sur la fonction
** correspondante.
*/

void	check_cmd(t_cmd *cmd, char **env)
{
	if (cmd->c_env == 1)
	if (cmd->c_setenv == 1)
	if (cmd->c_unset== 1)
	if (cmd->c_cd == 1)
	if (cmd->c_echo == 1)
	if (cmd->c_exit == 1)
}

/*
** parsing_cmd: Parse la string 'command' et vérifie si la command passée par
** l'user correspond a un builtin, si c'est le cas la valeur correspondant
** a la commande saisie par l'user est passée a 1.
*/

void	parsing_cmd(char *command, t_cmd *cmd)
{
	if (ft_strcmp(command, "env") == 0)
		cmd->c_env = 1;
	else if (ft_strcmp(command, "setenv") == 0)
		cmd->c_setenv = 1;
	else if (ft_strcmp(command, "unsetenv") == 0)
		cmd->c_unset = 1;
	else if (ft_strcmp(command, "cd") == 0)
		cmd->c_cd = 1;
	else if (ft_strcmp(command, "echo") == 0)
		cmd->c_echo = 1;
	else if (ft_strcmp(command, "exit") == 0)
		cmd->c_exit = 1;
}
