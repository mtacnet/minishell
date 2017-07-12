/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:34:51 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/11 15:56:00 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 ** if_path: Prend en parametre un path d'acces valide (usr/bin/cd par exemple)
 ** Prend en second arg un tableau contenant en pos[0] la commande et en pos[1]
 ** l'option ou le path au quel on souhaite accéder. Pour finir, le 3ieme arg
 ** contient la copie de l'environnement actuel.
*/

void	if_path(char *valid_path, char **tab_arg, char **env)
{
	pid_t		child_pid;
	int			status;

	child_pid = fork();
	if (child_pid == -1)
	{
		ft_putstr_fd("ERROR WITH CHIELD PROCESSUS", 2);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(valid_path, tab_arg, env);
		exit(0);
	}
	else
	{
		waitpid(child_pid, &status, WUNTRACED);
	}
}
