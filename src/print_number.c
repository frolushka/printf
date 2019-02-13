/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 01:23:51 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/03 22:30:04 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void inline	print_number_sign(t_info *i)
{
	if (i->cfs & FLAG_plus || i->cfs & FLAG_space)
		i->len += write(i->fd, i->cfs & FLAG_plus ? "+" : " ", 1);
	else if (i->cfs & FLAG_neg)
		i->len += write(i->fd, "-", 1);
}

static void inline	print_number_width(t_info *i)
{
	int ind;
	int len;

	if ((len = (int)ft_strlen(i->tmp)) <= i->pre)
		len = i->pre;
	if ((i->cfs & (FLAG_neg | FLAG_plus | FLAG_space)) >= 1)
		--i->wid;
	ind = -1;
	if (i->pre >= 0)
	{
		while (i->wid > len + ++ind)
			i->len += write(i->fd, " ", 1);
		ind = (int)ft_strlen(i->tmp) - 1;
		while (++ind < len)
			i->len += write(i->fd, "0", 1);
	}
	else
	{
		while (i->wid > len + ++ind)
			i->len += write(i->fd, i->cfs & FLAG_zero ? "0" : " ", 1);
	}
}

static void inline	prec_number(t_info *i)
{
	char	*tmp;
	char	*res;
	int		ind;
	int		len;

	if (i->tmp[0] == '-')
	{
		tmp = ft_strdup(i->tmp + 1);
		free(i->tmp);
		i->tmp = tmp;
		i->cfs &= ~FLAG_plus & ~FLAG_space;
		i->cfs |= FLAG_neg;
	}
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
		i->tmp = res;
	}
	if (i->tmp[0] == '0' && i->pre == 0)
	{
		free(i->tmp);
		i->tmp = ft_strdup("");
	}
}

void				print_number(t_info *i)
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

void				prep_number(t_info *i)
{
	long	tmp;

	tmp = va_arg(i->va, long);
	if (i->cfs & FLAG_j)
		i->tmp = ft_ltoa((intmax_t)tmp);
	else if (i->cfs & FLAG_z)
		i->tmp = ft_ltoa((size_t)tmp);
	else if (i->cfs & FLAG_ll)
		i->tmp = ft_ltoa((long long)tmp);
	else if (i->cfs & FLAG_l)
		i->tmp = ft_ltoa(tmp);
	else if (i->cfs & FLAG_h)
		i->tmp = ft_itoa((short)tmp);
	else if (i->cfs & FLAG_hh)
		i->tmp = ft_itoa((char)tmp);
	else
		i->tmp = ft_itoa((int)tmp);
	prec_number(i);
	print_number(i);
}