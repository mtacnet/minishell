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
	while (tab[i] && tab[i][0] != '\0')
	{
		ft_putendl(tab[i]);
		i++;
	}
}*/

static char		**cpy_env(char **environ)
{
	int		i;
	char	**tab;

	i = 0;
	tab = NULL;
	while (environ[i] != '\0')
		i++;
	tab = ft_memalloc(sizeof(*tab) * i + 1);
	i = 0;
	while (environ[i] != '\0')
	{
		tab[i] = environ[i];
		i++;
	}
	return (tab);
}

int		main(int argc, char **argv, char **environ)
{
	char	**env;

	env = NULL;
	if (!(argv))
		ft_putnbr(argc);
	env = cpy_env(environ);
//	view_tab(env);
	get_path(env);
//	get_line();
	return (0);
}
