/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 10:46:43 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/27 12:08:08 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_path(char **env)
{

}

void	get_line(void)
{
	char	*line;
	int		ret;

	line = NULL;
	while (1)
	{
		ft_putstr("$> ");
		while ((ret = get_next_line(0, &line) > 0))
		{
			printf("%s\n", line);
			ft_putstr("$> ");
		}
	}
}
