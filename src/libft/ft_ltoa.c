/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 01:26:59 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/02 23:49:39 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t inline	ft_longlen(long n)
{
	size_t	res;

	res = 1;
	if (n < 0)
		++res;
	while (n /= 10)
		++res;
	return (res);
}

char	*ft_ltoa(long long n)
{
	char	*res;
	size_t	e;

	e = ft_longlen(n);
	if (!(res = (char *)malloc(e + 1)))
		return (NULL);
	res[e--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		if (n == LLONG_MIN)
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