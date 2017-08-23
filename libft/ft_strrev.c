/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:23:41 by mtacnet           #+#    #+#             */
/*   Updated: 2016/12/18 15:39:39 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*ret;
	int		n;
	int		i;

	n = 0;
	i = ft_strlen(str);
	ret = ft_strnew(i--);
	while (i >= 0)
	{
		ret[i] = str[n];
		n++;
		i--;
	}
	return (ret);
}
