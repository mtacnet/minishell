/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:34:14 by mtacnet           #+#    #+#             */
/*   Updated: 2016/12/13 13:52:25 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	len = ft_strlen(little);
	if (!len)
		return ((char *)big);
	while (big[i] && i < n)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && little[j] && i + j < n)
			j++;
		if (j == len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
