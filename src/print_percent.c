/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 00:41:58 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/30 00:44:01 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_info *i)
{
	if (i->cfs & FLAG_minus)
	{
		i->len += write(i->fd, "%", 1);
		while (i->wid-- > 1)
			i->len += write(i->fd, " ", 1);
	}
	else
	{
		while (i->wid-- > 1)
			i->len += write(i->fd, (i->cfs & FLAG_zero ? "0" : " "), 1);
		i->len += write(i->fd, "%", 1);
	}
	++i->ind;
}