/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 00:08:53 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/01 21:49:24 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void inline	print_null(t_info *i)
{
	int len;

	len = (i->pre < 0 ? 6 : i->pre);
	while (i->wid-- > len)
		i->len += write(i->fd, (i->cfs & FLAG_zero ? "0" : " "), 1);
	i->len += write(i->fd, "(null)", len);
	++i->ind;
}