/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:38:51 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/09 17:46:54 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t inline	ft_doublelen(long double n)
{
	size_t	res;

	res = 1;
	if (n < 0)
		++res;
	while ((n /= 10) < 1)
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

char	*dtoa(t_info *i, long double tmp)
{

}

void	prep_double(t_info *i)
{
	long double	tmp;

	tmp = va_arg(i->va, long double);
	if (i->cfs & FLAG_L)
		i->tmp = dtoa(i, tmp);
	else
		i->tmp = dtoa(i, (double)tmp);
}