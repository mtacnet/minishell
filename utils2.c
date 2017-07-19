/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 13:11:07 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/19 12:48:54 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** verif_list: Permet de verifier que la liste passée en parametre contient 
** ou pas un des elements du tableau qui correspond aux arguments saisies par
** l'utilisateur.
*/

int		verif_list(t_elem *lst, char *tab_arg)
{
	int			i;
	size_t		size_arg;

	i = 0;
	size_arg = ft_strlen(tab_arg);
	while (lst != NULL)
	{
		if (ft_strncmp(lst->content, tab_arg, size_arg) == 0)
			i++;
		lst = lst->next;
	}
	if (i > 0)
		return (1);
	else
		return (0);
}

int		verif_tab(char *tab_arg)
{
	int		size_arg;

	size_arg = ft_strlen(tab_arg);
	if (tab_arg[size_arg - 1] == 075)
		return (0);
	else
		return (1);
}
