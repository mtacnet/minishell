/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:30:32 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/22 13:27:42 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	**list_to_tab(t_elem **lst)
{
	int			i;
	size_t		j;
	char		**tab;
	t_elem		*head;

	i = 0;
	j = 0;
	tab = NULL;
	head = (*lst);
	while ((*lst) != NULL)
	{
		j++;
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
	if (!(tab = ft_memalloc(sizeof(*tab) * (j + 1))))
		exit(EXIT_FAILURE);
	while ((*lst) != NULL)
	{
		tab[i] = (*lst)->content;
		(*lst) = (*lst)->next;
		i++;
	}
	(*lst) = head;
	return (tab);
}

void	tab_to_list(t_elem **lst, char **tab)
{
	int		i;

	i = 0;
	while (tab[i] && tab[i][0] != '\0')
	{
		push_elem(lst, tab[i]);
		i++;
	}
}

void	supp_elem_tab(char **tab, int value)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] && tab[i][0] != '\0')
		i++;
	if (value >= i)
		return ;
	else
	{
		while (j < i)
		{
			//ft_strdel(&(tab[j]))
	//		tab[j] = ft_strdup(tab[j + 1]);
			tab[j] = tab[j + 1];
			j++;
		}
	}
	return ;
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0])
		{
			ft_strdel(&(tab[i]));
			i++;
		}
		else
			i++;
	}
	free(tab);
	tab = NULL;
}

/*void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] && tab[i][0] != '\0')
		i++;
	while (i >= 0)
	{
		ft_strdel(&tab[i]);
		i--;
	}
	free(tab);
	tab = NULL;
}*/
