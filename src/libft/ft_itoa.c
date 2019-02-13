/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:25:09 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/02 02:18:31 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t inline	ft_intlen(int n)
{
	size_t	res;

	res = 1;
	while (n /= 10)
		++res;
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	e;

	e = ft_nbrlen(n);
	if (!(res = (char *)malloc(e + 1)))
		return (NULL);
	res[e--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		if (n == INT_MIN)
		{
			res[e--] = '8';
			n /= 10;
		}
		n *= -1;
	}
	res[e--] = n % 10 + '0';
	while (n /= 10)
		res[e--] = n % 10 + '0';
	return (res);
}
