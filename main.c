/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:54:29 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/18 11:05:07 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**set_env(void)
{
	char	*tmp;
	char	**tab;
	int		i;

	i = 0;
	tmp = getcwd(NULL, 0);
	tab = ft_memalloc(sizeof(*tab) * (3 + 1));
	if (tmp == NULL || tab == NULL)
		exit(EXIT_FAILURE);
	tab[0] = tmp;
	tab[1] = "SHLVL=1";
	tab[2] = "_=/usr/bin/env";
	tab[3] = "\0";
	return (tab);
}

static char		**cpy_env(char **environ)
{
	int		i;
	char	**tab;

	i = 0;
	tab = NULL;
	while (environ[i] != '\0')
		i++;
	if (!(tab = ft_memalloc(sizeof(*tab) * (i + 1))))
		exit(EXIT_FAILURE);
	i = 0;
	while (environ[i] != '\0')
	{
		tab[i] = environ[i];
		i++;
	}
	return (tab);
}

int				main(void)
{
	extern char		**environ;
	char			**env;

	env = NULL;
	if (environ)
	{
		if (environ[0] == NULL)
			env = set_env();
		else
			env = cpy_env(environ);
	}
	get_line(env);
	return (0);
}
