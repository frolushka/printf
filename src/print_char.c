/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 22:31:46 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/06 20:47:17 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_info *i)
{
	if (i->cfs & FLAG_minus)
	{
		i->len += write(i->fd, i->tmp, 1);
		while (i->wid-- > 1)
			i->len += write(i->fd, (i->cfs & FLAG_zero ? "0" : " "), 1);
	}
	else
	{
		while (i->wid-- > 1)
			i->len += write(i->fd, (i->cfs & FLAG_zero ? "0" : " "), 1);
		i->len += write(i->fd, i->tmp, 1);
	}
	++i->ind;
	free(i->tmp);
	i->tmp = NULL;
}

void	prep_char(t_info *i)
{
	int		c;

	c = va_arg(i->va, int);
	if (i->cfs & FLAG_l)
		print_wchar(i, c);
	else
	{
		i->tmp = ft_strnew(1);
		i->tmp[0] = c;
		print_char(i);
	}
}