/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 10:46:43 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/21 10:27:24 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** free_tab: Permet de libérer la mémoire allouée dynamiquement pour une
** variable de type char ** et retourne un char ** NULL
*/

static char		**free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] && tab[i][0] != '\0')
		i++;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

/*
** list_path: Lecture du tableau renvoyé par ft_strsplit résultant de la
** découpe des différents paths d'accès aux exéc. situés dans la var "PATH="
*/

static void		list_path(char **path, char **env)
{
	t_elem		*lst_path;
	int			i;

	lst_path = new_list();
	i = 0;
	while (path[i] && path[i][0] != '\0')
	{
		lst_path = push_elem(lst_path, "PATH", path[i]);
		free(path[i]);
		i++;
	}
	free(path);
	path = NULL;
	get_line(lst_path, env);
}

/*
** get_elem: Prend en parametre une copie de l'env et le nom d'un element de
** l'environnement (ex: PATH=)
** Envoi a la fonction "list_path" un tableau contenant les différents éléments
** récupérés dans la variable de d'environnement passé en parametre
*/

void			get_elem(char **env, char *elem)
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
	tmp_tab = ft_strsplit(env[j], ':'); // Découpage des éléments (ici: "¨PATH=")
	name_len = ft_strlen(tmp_tab[0]);
	tmp_tab[0] = ft_strsub(tmp_tab[0], 5, name_len);
	//view_tab(tmp_tab);
	list_path(tmp_tab, env);
}

/*
** get_line: Affiche un prompt puis split la chaine saisie par l'Users
** Les mots sont d'abord placés dans le tableau "tab_arg"
** Le tableau "tab_arg" est envoyé à la fonction "save_arg" qui va parcourir
** "tab_arg" pour ajouter ses directement élements dans la liste "lst_arg"
*/

void			get_line(t_elem *lst_path, char **env)
{
	char		*line;
	char		**tab_arg;
	int			ret;
	t_elem		*lst_env;

	lst_env = new_list();
	tab_to_list(&lst_env, env);
	tab_arg = NULL;
	line = NULL;
	while (1)
	{
		ft_putstr("$> ");
		while ((ret = get_next_line(1, &line) > 0))
		{
			if (verif_line(line) == 1)
				ft_putstr("$> ");
			else
			{
				modif_line(&line);
				tab_arg = ft_strsplit(line, 040);
				if (tab_arg[0] != NULL)
				{
					if (check_cmd(parsing_cmd(tab_arg[0]), lst_env, tab_arg) == 0)
					{
						recup_param(lst_path, tab_arg, env);
						tab_arg = free_tab(tab_arg);
						if (tab_arg != NULL)
							ft_putendl("ERROR");
					}
				}
				ft_putstr("$> ");
			}
		}
	}
}
