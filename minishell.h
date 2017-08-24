/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:54:43 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/24 14:07:14 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"

typedef struct		s_elem
{
	char			*content;
	struct s_elem	*next;
}					t_elem;

/*
** LIST_FUNCTIONS
*/

t_elem				*new_list(void);
t_elem				*init_element(t_elem *element);
int					is_empty(t_elem **lst);
void				push_elem(t_elem **lst, char *content);
void				supp_elem(t_elem **lst, char *arg);
void				push_back(t_elem **lst, char *content);
void				freelst(t_elem **lst);
void				view_list(t_elem **lst);
void				cpy_lst(t_elem **lst_dest, t_elem **lst_src);

/*
** MAIN_FUNCTIONS
*/

void				error(int value, char *bad_cmd, char *bad_flag);
void				get_line(char **env);
void				process_core(char *line, char **tab_arg, t_elem **lst_env,
		char **env);
void				get_elem(t_elem **lst_path, char **env, char *elem);
void				free_tab(char **tab);
void				tab_to_list(t_elem **lst, char **tab);
void				modif_line(char **line);
void				recup_param(t_elem **lst_path, char **tab_arg, char **env);
void				if_path(char *valid_path, char **tab_arg, char **env);
void				process_flag_i(t_elem **lst_path, char **tab_arg);
void				supp_elem_tab(char **tab, int value);
void				change_dir(char *path, t_elem **lst_env);
void				add_old_pwd(t_elem **lst_env);
void				go_path(t_elem **lst_env, char **tab);
void				process_cd2(t_elem **lst_env, char **tab_arg);
void				go_bin(t_elem **lst_path, t_elem **lst_env, char **tab_arg);
void				view_tab(char **tab);
int					check_access(char *path);
int					verif_line(char *line);
int					parsing_cmd(char *command);
void				check_cmd(int val, t_elem **lst_env, char **tab_arg,
		t_elem **lst_path);
char				**list_to_tab(t_elem **lst);
int					verif_tab(char *tab);
int					verif_list(t_elem **lst, char *tab_arg);
int					modif_list(t_elem **lst, char *arg);
int					check_old_pwd(t_elem **lst_env);
char				*go_home(t_elem **lst_env);
char				*go_old_pwd(t_elem **lst_env);

/*
** BULTINS_FUNCTIONS
*/

void				process_env(t_elem **lst_env, int val, char **tab_arg,
		t_elem **lst_path);
void				process_tmp_env(char **tab_arg, t_elem **lst_env,
		t_elem **lst_path);
void				process_f_env(t_elem **lst_env, char **tab_arg,
		t_elem **lst_path);
void				process_bin(char **tab_arg, t_elem **lst_env,
		t_elem **lst_path);
void				process_exit(t_elem **lst_env, t_elem **lst_path,
		char **tab_arg);
void				process_echo(char **tab);
void				process_cd(t_elem **lst_env, char **tab_arg);
void				process_unset(t_elem **lst_env, char **tab_arg);
#endif
