/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 13:11:07 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/21 13:47:10 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		modif_list(t_elem *lst, char *arg)
{
	int			i;
	int			j;
	size_t		size_arg;

	i = 0;
	j = 0;
	size_arg = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '=')
			size_arg = i - 1;
		i++;
	}
	i = 0;
	while (lst != NULL)
	{
		if (ft_strncmp(lst->content, arg, size_arg) == 0)
			return (1);
		lst = lst->next;
	}
	return (0);
}

/*
** verif_list: Permet de verifier que la liste passée en parametre contient
** ou pas un des elements du tableau qui correspond aux arguments saisies par
** l'utilisateur.
*/

int		verif_list(t_elem *lst, char *tab_arg)
{
	int			i;
	int			j;
	size_t		size_arg;

	i = 0;
	j = 0;
	size_arg = 0;
	while (tab_arg[j] != '\0')
	{
		if (tab_arg[j] == '=')
			size_arg = j;
		j++;
	}
	while (lst != NULL)
	{
		if (ft_strncmp(lst->content, tab_arg, size_arg) == 0)
		{
			free(lst->content);
			lst->content = ft_strdup(tab_arg);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

int		verif_tab(char *tab_arg)
{
	int		i;

	i = 0;
	while (tab_arg[i] != '\0')
	{
		if (tab_arg[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

int		verif_line(char *line)
{
	int		i;

	i = 0;
	if (line && !line[0])
		return (1);
	return (0);
}

void	modif_line(char **line)
{
	int		i;

	i = 0;
	while (line[0][i])
	{
		if (line[0][i] == '\t')
			line[0][i] = 040;
		i++;
	}
}
