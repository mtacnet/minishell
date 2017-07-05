/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:27:47 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/27 12:08:11 by mtacnet          ###   ########.fr       */
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
void				freelst(t_elem *lst);
void				view_list(t_elem *lst);
int					is_empty(t_elem *lst);

/*
 ** MAIN FONCTIONS
*/

void				get_elem(char **env, char *elem);
void				ft_strtrunc(char *str, char *word);
void				get_line(void);
void				view_tab(char **tab);

#endif
