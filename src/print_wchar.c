/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.wc                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:00:55 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/04 03:08:29 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void inline	put_char(t_info *i, char c)
{
	i->len += write(i->fd, &c, 1);
}

void				put_wchar(t_info *i, wchar_t wc)
{
	if (wc <= 0x7F)
		put_char(i, wc);
	else if (wc <= 0x7FF)
	{
		put_char(i, (wc >> 6) + 0xC0);
		put_char(i, (wc & 0x3F) + 0x80);
	}
	else if (wc <= 0xFFFF)
	{
		put_char(i, ((wc >> 12) + 0xE0));
		put_char(i, ((wc >> 6) & 0x3F) + 0x80);
		put_char(i, (wc & 0x3F) + 0x80);
	}
	else if (wc <= 0x10FFFF)
	{
		put_char(i, (wc >> 18) + 0xF0);
		put_char(i, ((wc >> 12) & 0x3F) + 0x80);
		put_char(i, ((wc >> 6) & 0x3F) + 0x80);
		put_char(i, (wc & 0x3F) + 0x80);
	}
}

void				print_wchar(t_info *i, wchar_t wc)
{
	if (wc <= 0x7F)
	 	--i->wid;
	else if (wc <= 0x7FF)
		i->wid -= 2;
	else if (wc <= 0xFFFF)
		i->wid -= 3;
	else if (wc <= 0x10FFFF)
		i->wid -= 4;
	if (i->cfs & FLAG_minus)
	{
		put_wchar(i, wc);
		while (i->wid-- > 0)
			i->len += write(i->fd, " ", 1);
	}
	else
	{
		while (i->wid-- > 0)
			i->len += write(i->fd, (i->cfs & FLAG_zero ? "0" : " "), 1);
		put_wchar(i, wc);
	}
	++i->ind;
}

void				prep_wchar(t_info *i)
{
	wchar_t	c;

	c = va_arg(i->va, wchar_t);
	print_wchar(i, c);
}