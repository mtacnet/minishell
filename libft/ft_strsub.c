/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:56:42 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/30 12:31:28 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	ret = NULL;
	if (s)
	{
		if ((ret = ft_strnew(len + 1)) == NULL)
			return (NULL);
		i = -1;
		while (++i < len)
			ret[i] = s[start + i];
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
