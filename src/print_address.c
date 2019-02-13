/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 00:20:08 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/06 20:16:49 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void inline	print_address_width(t_info *i)
{
	size_t	len;

	len = ft_strlen(i->tmp);
	while (i->wid-- > len)
		i->len += write(i->fd, " ", 1);
}

static void inline	preс_address(t_info *i)
{
	char	*tmp;
	char	*res;
	int		ind;
	int		len;

	ind = -1;
	len = (int)ft_strlen(i->tmp);
	res = i->tmp;
	if (i->pre > len)
	{
		tmp = ft_strnew(i->pre - len);
		while (++ind < i->pre - len)
			tmp[ind] = '0';
		res = ft_strjoin(tmp, i->tmp);
		free(i->tmp);
		free(tmp);
	}
	if (i->cfs & FLAG_sharp)
		i->tmp = ft_strjoin((i->cfs & FLAG_up ? "0X" : "0x"), res);
	free(res);
}

void				print_address(t_info *i)
{
	if (i->cfs & FLAG_minus)
	{
		i->len += write(i->fd, i->tmp, ft_strlen(i->tmp));
		print_address_width(i);
	}
	else
	{
		print_address_width(i);
		i->len += write(i->fd, i->tmp, ft_strlen(i->tmp));
	}
	++i->ind;
	free(i->tmp);
	i->tmp = NULL;
}

void				prep_address(t_info *i)
{
	long	tmp;

	tmp = va_arg(i->va, long);
	if (i->pre == 0)
		i->tmp = ft_strdup("");
	else
		i->tmp = ft_ultoa_base((unsigned long)tmp, 16);
	if (i->cfs & FLAG_zero && i->pre == -1)
		i->pre = i->wid - 2;
	preс_address(i);
	if (!(i->cfs & FLAG_up))
		ft_strlow(i->tmp);
	print_address(i);
}