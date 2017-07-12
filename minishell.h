/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:27:47 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/12 14:49:44 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"

typedef struct		s_cmd
{
	int				c_env;
	int				c_setenv;
	int				c_unset;
	int				c_cd;
	int				c_echo;
	int				c_exit;
}					t_cmd;

typedef struct		s_elem
{
	char			*name;
	char			*content;
	struct s_elem	*next;
}					t_elem;

/*
** LIST FONCTIONS
*/

t_elem				*new_list(void);
t_elem				*init_element(t_elem *element);
t_elem				*push_elem(t_elem *lst, char *name, char *content);
void				save_arg(char **tab_arg, t_elem **lst_arg);
void				freelst(t_elem *lst);
void				init_struct_cmd(t_cmd *cmd);
void				view_list(t_elem *lst);
int					is_empty(t_elem *lst);

/*
** MAIN FONCTIONS
*/

void				get_elem(char **env, char *elem);
void				ft_strtrunc(char *str, char *word);
void				get_line(t_elem *lst_path, char **env);
void				view_tab(char **tab);
void				recup_param(t_elem *lst_path, char **tab_arg, char **env);
void				if_path(char *valid_path, char **tab_arg, char **env);
void				parsing_cmd(char *command, char **env);
#endif
