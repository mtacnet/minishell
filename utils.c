/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:36:58 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/18 17:50:16 by mtacnet          ###   ########.fr       */
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
** check_cmd: Vérifie la valeur passée en paramètre et redirige vers la fonction
** correspond a la commande saisie par l'utilisateur.
*/

int		check_cmd(int value, char **env, char **tab_arg)
{
	if (value != 0)
	{
		if (value == 1 || value == 2 || value == 3)
			process_env(env, value, tab_arg);
		if (value == 4)
			process_cd(env);
		if (value == 5)
			process_echo(env);
		if (value == 6)
			process_exit(env);
		return (1);
	}
	else
		return (0);
}

/*
** parsing_cmd: Parse la string 'command' et vérifie si la command passée par
** l'user correspond a un builtin, si c'est le cas une valeur comprise entre 0
** et 6 est retournée pour ensuitre etre analysée par la fonction check_cmd.
*/

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
