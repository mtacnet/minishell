/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:56:42 by mtacnet           #+#    #+#             */
/*   Updated: 2017/01/28 13:35:49 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (s)
	{
		if ((ret = ft_strnew(len)) == NULL)
			return (NULL);
		i = -1;
		while (++i < len)
			ret[i] = s[start + i];
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
