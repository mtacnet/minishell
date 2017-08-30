/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:54:29 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/30 12:07:00 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**set_env(void)
{
	t_elem		*lst;
	char		*tmp;
	char		*tmp1;
	char		**tab;

	tmp = getcwd(NULL, 0);
	tmp1 = ft_strjoin("PWD=", tmp);
	tab = NULL;
	lst = new_list();
	push_elem(&lst, tmp1);
	push_elem(&lst, "SHLVL=1");
	push_elem(&lst, "_=/usr/bin/env");
	ft_strdel(&tmp);
	ft_strdel(&tmp1);
	tab = list_to_tab(&lst);
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
