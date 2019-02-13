/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:15:03 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/08 16:37:37 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			get_wstring_len(wchar_t *ws)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (ws[++i])
	{
		if (ws[i] <= 0x7F)
			++res;
		else if (ws[i] <= 0x7FF)
			res += 2;
		else if (ws[i] <= 0xFFFF)
			res += 3;
		else if (ws[i] <= 0x10FFFF)
			res += 4;
	}
	return (res);
}

static int			get_wchar_len(wchar_t wc)
{
	if (wc <= 0x7F)
		return (1);
	if (wc <= 0x7FF)
		return (2);
	if (wc <= 0xFFFF)
		return (3);
	if (wc <= 0x10FFFF)
		return (4);
	return (0);
}

static void inline	print_wstring_width(t_info *i, wchar_t *ws)
{
	int	len;

	len = get_wstring_len(ws);
	while (i->wid-- > len)
		i->len += write(i->fd, (i->cfs & FLAG_zero ? "0" : " "), 1);
}

void				put_wstring(t_info *i, wchar_t *ws)
{
	int	ind;
	int len;

	ind = -1;
	len = 0;
	while (ws[++ind] && (len += get_wchar_len(ws[ind])) <= i->wid)
		put_wchar(i, ws[ind]);
}

void				print_wstring(t_info *i, wchar_t *ws)
{
	// if (i->pre >= 0 && i->pre < get_wstring_len(ws))
	// {
	// 	tmp = ft_strsub(i->tmp, 0, i->pre);
	// 	free(i->tmp);
	// 	i->tmp = tmp;
	// }
	if (i->cfs & FLAG_minus)
	{
		put_wstring(i, ws);
		print_wstring_width(i, ws);
	}
	else
	{
		print_wstring_width(i, ws);
		put_wstring(i, ws);
	}
	++i->ind;
}

void				prep_wstring(t_info *i)
{
	wchar_t *tmp;
	size_t	len;

	tmp = va_arg(i->va, wchar_t *);
	tmp = (tmp != NULL ? ft_memcpy(tmp, tmp, len = get_wstring_len(tmp)) : NULL);
	if (tmp == NULL)
	{
		print_null(i);
		return ;
	}
	if (i->pre < len)
		print_wstring(i, tmp);
}