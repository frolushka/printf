/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 00:49:43 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/02 03:08:52 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void inline	clear_info(t_info *i)
{
	i->cfs = 0;
	i->pre = -1;
	i->wid = 0;
}

static void inline	parse_conversion(t_info *i, char const *f)
{
	++i->ind;
	set_flag(i, f);
	set_spec(i, f);
	clear_info(i);
}

int					ft_printf(char const *f, ...)
{
	t_info		i;

	if (!f)
		return (0);
	ft_bzero(&i, sizeof(i));
	va_start(i.va, f);
	i.fd = 1;
	i.pre = -1;
	while (f[i.ind])
	{
		if (f[i.ind] == '%')
			parse_conversion(&i, f);
		else
			i.len += write(i.fd, f + i.ind++, 1);
	}
	va_end(i.va);
	return (i.len);
}