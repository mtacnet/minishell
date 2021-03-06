/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:22:03 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/23 16:48:26 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_old_pwd(t_elem **lst_env)
{
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	tmp1 = "OLDPWD=";
	tmp2 = NULL;
	if ((tmp = getcwd(NULL, 0)) != NULL)
	{
		tmp2 = ft_strjoin(tmp1, tmp);
		push_elem(lst_env, tmp2);
	}
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}

int		check_old_pwd(t_elem **lst_env)
{
	t_elem		*head;
	int			i;

	i = 0;
	head = (*lst_env);
	while ((*lst_env) != NULL)
	{
		if (ft_strncmp((*lst_env)->content, "OLDPWD=", 7) == 0)
			i++;
		(*lst_env) = (*lst_env)->next;
	}
	(*lst_env) = head;
	if (i == 0)
		return (0);
	else
		return (1);
}

void	change_dir(char *path, t_elem **lst_env)
{
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	if ((tmp = getcwd(NULL, 0)) != NULL)
	{
		tmp1 = "OLDPWD=";
		tmp2 = ft_strjoin(tmp1, tmp);
		ft_strdel(&tmp);
		supp_elem(lst_env, "OLDPWD=");
		push_elem(lst_env, tmp2);
		ft_strdel(&tmp2);
	}
	chdir(path);
	if ((tmp = getcwd(NULL, 0)) != NULL)
	{
		tmp1 = "PWD=";
		ft_putstr("repertoire actuel: ");
		ft_putendl(tmp);
		tmp2 = ft_strjoin(tmp1, tmp);
		ft_strdel(&tmp);
		supp_elem(lst_env, "PWD=");
		push_elem(lst_env, tmp2);
		ft_strdel(&tmp2);
	}
}

char	*go_old_pwd(t_elem **lst_env)
{
	t_elem		*head;
	char		*tmp;
	size_t		i;

	head = (*lst_env);
	tmp = NULL;
	i = 0;
	while (head != NULL)
	{
		if (ft_strncmp(head->content, "OLDPWD=", 7) == 0)
		{
			i = ft_strlen(head->content);
			tmp = ft_strsub(head->content, 7, i);
		}
		head = head->next;
	}
	return (tmp);
}

char	*go_home(t_elem **lst_env)
{
	t_elem		*head;
	char		*tmp;
	size_t		i;

	head = (*lst_env);
	tmp = NULL;
	i = 0;
	while (head != NULL)
	{
		if (ft_strncmp(head->content, "HOME=", 5) == 0)
		{
			i = ft_strlen(head->content);
			tmp = ft_strsub(head->content, 5, i);
		}
		head = head->next;
	}
	return (tmp);
}
