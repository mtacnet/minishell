/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 11:42:44 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/23 15:28:29 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		view_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] && tab[i][0])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

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
	char	**tb_env;

	if (argv == NULL)
		ft_putnbr(argc);
	tb_env = NULL;
	tb_env = cpy_env(envp);
	view_tab(tb_env);
	return (0);
}
