/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unumber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:00:01 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/09 17:36:12 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void inline	print_number_sign(t_info *i)
{
	if (i->cfs & FLAG_sharp && i->bas == 8)
		i->len += write(i->fd, "0", 1);
	if (i->cfs & FLAG_sharp && i->bas == 16)
		i->len += write(i->fd, i->cfs & FLAG_up ? "0X" : "0x", 2);
	if (i->cfs & FLAG_sharp && i->bas == 2)
		i->len += write(i->fd, i->cfs & FLAG_up ? "0B" : "0b", 2);
}

static void inline	print_number_width(t_info *i)
{
	int ind;
	int len;

	if ((len = (int)ft_strlen(i->tmp)) <= i->pre)
		len = i->pre;
	if ((i->cfs & (FLAG_plus | FLAG_space)) >= 1)
		--i->wid;
	ind = -1;
	if (i->pre >= 0)
	{
		while (i->wid - (i->bas == 8 && i->cfs & FLAG_sharp ? 1 : 0) - (i->bas == 16 && i->cfs & FLAG_sharp ? 2 : 0) > len + ++ind)
			i->len += write(i->fd, " ", 1);
		ind = (int)ft_strlen(i->tmp) - 1;
		while (++ind < len)
			i->len += write(i->fd, "0", 1);
	}
	else
	{
		while (i->wid - (i->bas == 8 && i->cfs & FLAG_sharp ? 1 : 0) - (i->bas == 16 && i->cfs & FLAG_sharp ? 2 : 0) > len + ++ind)
			i->len += write(i->fd, i->cfs & FLAG_zero ? "0" : " ", 1);
	}
}

static void inline	prec_number(t_info *i)
{
	char	*tmp;
	char	*res;
	int		ind;
	int		len;

	ind = -1;
	len = (int)ft_strlen(i->tmp);
	res = i->tmp;
	if (i->cfs & FLAG_sharp && i->bas == 8 && i->pre > 0)
		--i->pre;
	// else if (i->cfs & FLAG_sharp && i->bas == 16)
	// 	i->pre -= 2;
	else if (i->pre == 0)
	{
		free(i->tmp);
		i->tmp = ft_strdup("");
	}
	if (i->pre > len)
	{
		tmp = ft_strnew(i->pre - len);
		while (++ind < i->pre - len)
			tmp[ind] = '0';
		res = ft_strjoin(tmp, i->tmp);
		free(i->tmp);
		free(tmp);
		i->tmp = res;
	}
}

void				print_unumber(t_info *i)
{
	if (i->cfs & FLAG_zero)
	{
		print_number_sign(i);
		print_number_width(i);
		i->len += write(i->fd, i->tmp, ft_strlen(i->tmp));
	}
	else if (i->cfs & FLAG_minus)
	{
		print_number_sign(i);
		i->len += write(i->fd, i->tmp, ft_strlen(i->tmp));
		print_number_width(i);
	}
	else
	{
		print_number_width(i);
		print_number_sign(i);
		i->len += write(i->fd, i->tmp, ft_strlen(i->tmp));
	}
	++i->ind;
	free(i->tmp);
	i->tmp = NULL;
}

void				prep_unumber(t_info *i)
{
	long	pre;
	long	tmp;

	pre = va_arg(i->va, long);
	(pre == 0 && i->bas != 8 ? i->cfs &= ~FLAG_sharp : 0);
	if (i->cfs & FLAG_j)
		i->tmp = ft_ultoa_base(tmp = (uintmax_t)pre, i->bas);
	else if (i->cfs & FLAG_z)
		i->tmp = ft_ultoa_base(tmp = (size_t)pre, i->bas);
	else if (i->cfs & FLAG_ll)
		i->tmp = ft_ultoa_base(tmp = (unsigned long long)pre, i->bas);
	else if (i->cfs & FLAG_l)
		i->tmp = ft_ultoa_base(tmp = (unsigned long)pre, i->bas);
	else if (i->cfs & FLAG_h)
		i->tmp = ft_ultoa_base(tmp = (unsigned short)pre, i->bas);
	else if (i->cfs & FLAG_hh)
		i->tmp = ft_ultoa_base(tmp = (unsigned char)pre, i->bas);
	else
		i->tmp = ft_ultoa_base(tmp = (unsigned int)pre, i->bas);
	if (!(i->cfs & FLAG_up))
		ft_strlow(i->tmp);
	prec_number(i);
	print_unumber(i);
}