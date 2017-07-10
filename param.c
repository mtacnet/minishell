#include "minishell.h"

/*
 ** check_access: Vérifie que le pathname passé en paramètre est valide via la
 ** fonction ACCESS. Si le pathname est valide on vérifie si il est exécutable
 ** Si exec alors return 1 Sinon return 0
*/

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

/*
 ** cpy_lst: Fait une copie des éléments de lst_path dans la liste path_concat
 ** puis retourne la liste path_concat.
*/

static t_elem		*cpy_lst(t_elem **path_concat, t_elem *lst_path)
{
	while (lst_path != NULL)
	{
		*path_concat = push_elem(*path_concat, lst_path->name, lst_path->content);
		lst_path = lst_path->next;
	}
	return (*path_concat);
}

/*
 ** recup_param: Fait une copie de la liste chainée 'lst_path' dans la liste
 ** path_concat qui servira ensuite a concaténer les paths contenus dans tab_arg
 ** avec la commande saisie par l'utilisateur dans la fonction get_line.
*/

void	recup_param(t_elem *lst_path, char **tab_arg, char **env)
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
		// FAIRE GESTION D'ERREUR via fonction check_access
		path_access = check_access(path_concat->content);
		ft_putnbr(path_access); //retourne la valeur de ACCESS associé au PATH
		ft_putendl("");
		if (path_access == 1)
			if_path(path_concat->content, tab_arg, env);
		path_concat = path_concat->next;
	}
	freelst(path_concat);
}
