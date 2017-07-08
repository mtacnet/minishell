#include "minishell.h"

static int		check_access(char *path_concat)
{
	int		ret_access;

	ret_access = access(path_concat, F_OK);
	if (ret_access == 0)
	{
		if (access(path_concat, X_OK) == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static t_elem		*cpy_lst(t_elem **path_concat, t_elem *lst_path)
{
	while (lst_path != NULL)
	{
		*path_concat = push_elem(*path_concat, lst_path->name, lst_path->content);
		lst_path = lst_path->next;
	}
	return (*path_concat);
}

void	recup_param(t_elem *lst_path, char **tab_arg)
{
	t_elem		*path_concat;
	int		path_access;

	path_concat = new_list();
	path_concat = cpy_lst(&path_concat, lst_path);
	path_access = 0;
	while (path_concat != NULL)
	{
		path_concat->content = ft_strjoin(path_concat->content, "/");
		path_concat->content = ft_strjoin(path_concat->content, tab_arg[0]);
		ft_putendl(path_concat->content);
		path_access = check_access(path_concat->content);
		ft_putnbr(path_access);
		ft_putendl("");
		path_concat = path_concat->next;
	}
	freelst(path_concat);
}
