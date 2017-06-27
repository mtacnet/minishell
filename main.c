/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 11:42:44 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/27 12:08:07 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static void		view_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] && tab[i][0])
	{
		ft_putendl(tab[i]);
		i++;
	}
}*/

static char		**cpy_env(char **envp)
{
	int		i;
	char	**tab;

	tab = NULL;
	i = 0;
	while (envp[i] != NULL)
		i++;
	tab = ft_memalloc(sizeof(*tab) * i);
	i = 0;
	while (envp[i] != NULL)
	{
		tab[i] = envp[i];
		i++;
	}
	return (tab);
}

int		main(int argc, char **argv, char **envp)
{
	char	**env;

	if (!(argv))
		ft_putnbr(argc);
	env = NULL;
	env = cpy_env(envp);
	get_path(env);
//	view_tab(env);
//	get_line();
	return (0);
}
