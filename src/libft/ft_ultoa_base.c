/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 01:21:49 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/02 19:09:38 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t inline	ft_ulonglen(unsigned long long n, int base)
{
	size_t	res;

	res = 1;
	while (n /= base)
		++res;
	return (res);
}

char					*ft_ultoa_base(unsigned long long n, int base)
{
	char	*res;
	size_t	e;

	e = ft_ulonglen(n, base);
	if (!(res = (char *)malloc(e + 1)))
		return (NULL);
	res[e--] = '\0';
	res[e--] = n % base > 9 ? n % base - 10 + 'A' : n % base + '0';
	while (n /= base)
		res[e--] = n % base > 9 ? n % base - 10 + 'A' : n % base + '0';
	return (res);
}