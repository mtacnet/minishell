/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 13:11:25 by mtacnet           #+#    #+#             */
/*   Updated: 2016/12/18 16:05:20 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	int		i;
	int		neg;
	char	*res;

	if (!(res = ft_strnew(ft_intlen(n) + 1)))
		return (NULL);
	i = 0;
	neg = 0;
	if (n < 0)
		neg = 1;
	else
		n = -n;
	if (n == 0)
		res[i++] = '0';
	while (n)
	{
		res[i++] = -(n % 10) + '0';
		n /= 10;
	}
	if (neg)
		res[i++] = '-';
	res[i] = '\0';
	return (ft_strrev(res));
}
