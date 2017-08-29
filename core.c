/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:04:46 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/29 11:45:55 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		list_path(t_elem **lst_path, char **path)
{
	int		i;

	i = 0;
	while (path[i] && path[i][0] != '\0')
	{
		push_elem(lst_path, path[i]);
		i++;
	}
	free_tab(path);
}

void			get_elem(t_elem **lst_path, char **env, char *elem)
{
	char		**tmp_tab;
	char		*tmp;
	size_t		i;
	size_t		j;
	size_t		name_len;

	tmp = NULL;
	i = 0;
	j = 0;
	name_len = 0;
	while (env[i] && env[i][0] != '\0')
	{
		if (ft_strncmp(env[i], elem, 4) == 0)
			j = i;
		i++;
	}
	if (j == 0)
		return ;
	tmp_tab = ft_strsplit(env[j], ':');
	name_len = ft_strlen(tmp_tab[0]);
	tmp = ft_strsub(tmp_tab[0], 5, name_len);
	ft_strdel(&tmp_tab[0]);
	tmp_tab[0] = ft_strsub(tmp, 0, name_len);
	list_path(lst_path, tmp_tab);
	ft_strdel(&tmp);
}

void			process_core(char *line, char **tab_arg, t_elem **lst_env,
		char **env)
{
	int		i;
	t_elem	*lst_path;

	i = 0;
	lst_path = new_list();
	get_elem(&lst_path, env, "PATH");
	modif_line(&line);
	tab_arg = ft_strsplit(line, 040);
	if (tab_arg[0] != NULL)
	{
		if ((i = parsing_cmd(tab_arg[0])) != 0)
			check_cmd(i, lst_env, tab_arg, &lst_path);
		else
			go_bin(&lst_path, lst_env, tab_arg);
		freelst(&lst_path);
		free_tab(tab_arg);
	}
	else
	{
		free_tab(tab_arg);
		freelst(&lst_path);
	}
}

void			if_path(char *valid_path, char **tab_arg, char **env)
{
	pid_t		child_pid;
	int			status;

	child_pid = fork();
	if (child_pid == -1)
	{
		ft_putstr_fd("ERROR WITH CHILD PROCESSUS", 2);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(valid_path, tab_arg, env);
		exit(0);
	}
	else
		waitpid(child_pid, &status, WUNTRACED);
}

void			get_line(char **env)
{
	char		*line;
	char		**tab_arg;
	t_elem		*lst_env;
	int			ret;

	line = NULL;
	tab_arg = NULL;
	lst_env = new_list();
	tab_to_list(&lst_env, env);
	ft_putstr("$> ");
	while (1)
	{
		while ((ret = get_next_line(0, &line)) > 0)
		{
			if (verif_line(line) == 1)
				ft_putstr("$> ");
			else
				process_core(line, tab_arg, &lst_env, env);
			ft_putstr("$> ");
			free(line);
		}
	}
}
