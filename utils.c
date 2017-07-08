#include "minishell.h"

/*
 ** save_arg: Enregistre le contenu du tableau dans la liste "lst_arg" passée
 ** en paramètre.
*/

void	save_arg(char **tab_arg, t_elem **lst_arg)
{
	int		i;

	i = 0;
	while (tab_arg[i] && tab_arg[i][0] != '\0')
	{
		*lst_arg = push_elem(*lst_arg, "CMD", tab_arg[i]);
		i++;
	}
}

/*
 ** view_tab: Affiche le contenu du tableau passé en paramètre.
*/

void	view_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] && tab[i][0] != '\0')
	{
		ft_putendl(tab[i]);
		i++;
	}
}
