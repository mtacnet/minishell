/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 13:11:07 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/18 17:50:16 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** verif_list: Permet de verifier que la liste passée en parametre contient 
** ou pas un des elements du tableau (a partir de tab[1] et, si il y a, tab[2])
*/
/*
int		verif_list(t_elem *lst, char **tab_arg)
{

}*/

void	verif_arg(char **tab_arg)
{
	if (tab_arg[2])
		ft_putendl(tab_arg[2]);
	else
		ft_putendl("PAS DE VALEUR");
}

int		verif_tab(char **tab_arg)
{
	int		size_arg;

	size_arg = ft_strlen(tab_arg[1]);
	if (tab_arg[1][size_arg - 1] == 075)
		return (0);
	else
		return (1);
}
