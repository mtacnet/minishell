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
	// FAIRE UN FREE DE **PATH
	view_list(lst_path); //TEST Affichage de la liste de paths: OK LST REMPLIE
	ft_putchar('\n');
	get_line();
}

/*
 ** get_elem: Prend en parametre une copie de l'env et le nom d'un element de
 ** l'environnement (ex: PATH=)
 ** Envoi a la fonction "list_path" un tableau contenant les différents éléments
 ** récupérés dans la variable de d'environnement passé en parametre
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
	tmp_tab = ft_strsplit(env[j], ':'); // Découpage des éléments (ici: "¨PATH=")
	name_len = ft_strlen(tmp_tab[0]);
	tmp_tab[0] = ft_strsub(tmp_tab[0], 5, name_len);
	list_path(tmp_tab);
}

/*
 ** get_line: Affiche un prompt puis split la chaine saisie par l'Users
 ** Les mots sont d'abord placés dans le tableau "tab_arg"
 ** Le tableau "tab_arg" est envoyé à la fonction "save_arg" qui va parcourir
 ** "tab_arg" pour ajouter ses directement élements dans la liste "lst_arg" 
*/

void	get_line(void)
{
	t_elem		*lst_arg;
	char		*line;
	char		**tab_arg;
	int			ret;

	lst_arg = new_list();
	tab_arg = NULL;
	line = NULL;
	while (1)
	{
		ft_putstr("$> ");
		while ((ret = get_next_line(1, &line) > 0))
		{
			tab_arg = ft_strsplit(line, 040);
			save_arg(tab_arg, &lst_arg);
			view_list(lst_arg); // TEST Affichage de la liste d'arg: OK LST REMPLIE
			//view_tab(tab_arg); // Affichage du tableau rempli d'arguments.
			ft_putstr("$> ");
			//ft_putendl(line); // Affiche la cmd saisie par l'utilisateur
		}
	}
}
