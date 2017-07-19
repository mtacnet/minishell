/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:27:47 by mtacnet           #+#    #+#             */
/*   Updated: 2017/07/19 14:04:15 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"

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
t_elem				*push_back(t_elem *lst, char *name, char *content);
void				save_arg(char **tab_arg, t_elem **lst_arg);
void				freelst(t_elem *lst);
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
void				tab_to_list(t_elem **lst_env, char **env);
int					parsing_cmd(char *command);
int					check_cmd(int value, t_elem *lst_env, char **tab_arg);
int					verif_list(t_elem *lst, char *tab_arg);
int					verif_tab(char *tab_arg);
/*
** PROCESS_BUILTINS
*/

void				process_env(t_elem *lst_env, int value, char **tab_arg);
void				process_cd(t_elem *lst_env);
void				process_echo(t_elem *lst_env);
void				process_exit(t_elem *lst_env);

#endif
