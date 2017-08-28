/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 14:58:36 by mtacnet           #+#    #+#             */
/*   Updated: 2017/08/28 14:59:03 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*result;
	size_t		i;

	if (!s || start > ft_strlen(s))
		return (NULL);
	if (!(result = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
		result[i++] = *(s++ + start);
	return (result);
}
