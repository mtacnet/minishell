/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 10:27:11 by mtacnet           #+#    #+#             */
/*   Updated: 2017/02/20 13:59:28 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_error(char **buffer, char **stock)
{
	ft_strdel(buffer);
	ft_strdel(stock);
	return (READ_ERR);
}

static int		ft_eof(char **line, char **stock, char **buffer)
{
	if (ft_strlen(*stock))
	{
		if (!(*line = ft_strdup(*stock)))
			return (ft_error(buffer, stock));
		ft_strdel(stock);
		ft_strdel(buffer);
		return (READ_LINE);
	}
	return (READ_END);
}

static int		ft_init_stock(char *tmp, char **stock, char **buffer)
{
	ft_strdel(stock);
	if (!(*stock = ft_strdup(tmp)))
		return (ft_error(buffer, stock));
	ft_strdel(&tmp);
	return (READ_LINE);
}

unsigned int	ft_strchri(char *stock, char c)
{
	if (ft_strchr(stock, c) != NULL)
		return ((ft_strchr(stock, c) - stock));
	return (READ_ERR);
}

int				get_next_line(const int fd, char **line)
{
	static char		*stock = NULL;
	char			*buffer;
	char			*tmp;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 1 || BUFF_SIZE > 10000000)
		return (READ_ERR);
	stock = (!stock) ? ft_strnew(BUFF_SIZE) : stock;
	while (!(ft_strchr(stock, '\n')))
	{
		buffer = ft_strnew(BUFF_SIZE);
		if (!(ret = read(fd, buffer, BUFF_SIZE)))
			return (ft_eof(line, &stock, &buffer));
		if (ret == -1 || !stock || !(tmp = ft_strjoin(stock, buffer)) ||
			ft_init_stock(tmp, &stock, &buffer) == -1)
			return (ft_error(&buffer, &stock));
		ft_strdel(&buffer);
	}
	if (!(*line = ft_strsub(stock, 0, ft_strchri(stock, '\n'))))
		return (ft_error(&buffer, &stock));
	if (!(tmp = ft_strsub(stock, ft_strchri(stock, '\n') + 1, ft_strlen(stock)))
		|| ft_init_stock(tmp, &stock, &buffer) == -1)
		return (ft_error(&buffer, &stock));
	return (READ_LINE);
}
