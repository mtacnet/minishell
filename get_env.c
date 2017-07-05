/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 10:46:43 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/27 12:08:08 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 ** list_path: Lecture du tableau renvoyé par ft_strsplit résultant de la 
 ** découpe des différents paths d'accès aux exéc. situés dans la var "PATH="
*/

static void		list_path(char **path)
{
	t_elem		*lst_path;
	int			i;

	lst_path = new_list();
	i = 0;
	while (path[i] && path[i][0] != '\0')
	{
		lst_path = push_elem(lst_path, "PATH", path[i]);
		i++;
	}
	view_list(lst_path);
	ft_putchar('\n');
	get_line();
}

/*
 ** get_elem: Prend en parametre une copie de l'env et le nom d'un element de
 ** l'environnement (ex: PATH=)
*/

void	get_elem(char **env, char *elem)
{
	char		**tmp_tab;
	size_t		name_len;
	size_t		i;
	size_t		j;

	tmp_tab = NULL;
	i = 0;
	j = 0;
	name_len = 0;
	while (env[i] && env[i][0] != '\0')
	{
		if (ft_strncmp(env[i], elem, 4) == 0)
			j = i;
		i++;
	}
	tmp_tab = ft_strsplit(env[j], ':');
	name_len = ft_strlen(tmp_tab[0]);
	tmp_tab[0] = ft_strsub(tmp_tab[0], 5, name_len);
	list_path(tmp_tab);
}

/*
 ** get_line: Affiche un prompt et retourne la chaine saisie par l'user.
*/

void	get_line(void)
{
	char	*line;
	int		ret;

	line = NULL;
	while (1)
	{
		ft_putstr("$> ");
		while ((ret = get_next_line(1, &line) > 0))
		{
			ft_putendl(line);
			ft_putstr("$> ");
		}
	}
}
