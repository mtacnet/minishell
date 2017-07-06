#include "minishell.h"

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
