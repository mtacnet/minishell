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

static char		**cpy_env(char **environ)
{
	int		i;
	char	**tab;

	i = 0;
	tab = NULL;
	while (environ[i] != '\0')
		i++;
	if (!(tab = ft_memalloc(sizeof(*tab) * i + 1)))
		exit(EXIT_FAILURE);
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
	get_elem(env, "PATH=");
	return (0);
}
