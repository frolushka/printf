/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 22:48:39 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/09 17:02:43 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void inline	print_string_width(t_info *i)
{
	int	len;

	len = ft_strlen(i->tmp);
	while (i->wid-- > len)
		i->len += write(i->fd, (i->cfs & FLAG_zero ? "0" : " "), 1);
}

void				print_string(t_info *i)
{
	char	*tmp;

	if (i->pre >= 0 && i->pre < (int)ft_strlen(i->tmp))
	{
		tmp = ft_strsub(i->tmp, 0, i->pre);
		free(i->tmp);
		i->tmp = tmp;
	}
	if (i->cfs & FLAG_minus)
	{
		i->len += write(i->fd, i->tmp, ft_strlen(i->tmp));
		print_string_width(i);
	}
	else
	{
		print_string_width(i);
		i->len += write(i->fd, i->tmp, ft_strlen(i->tmp));
	}
	++i->ind;
	free(i->tmp);
	i->tmp = NULL;
}

void	prep_string(t_info *i)
{
	wchar_t	*tmp;

	if (i->cfs & FLAG_l)
	{
		tmp = va_arg(i->va, wchar_t *);
		(tmp == NULL ? print_null(i) : print_wstring(i, tmp));
		return ;
	}
	i->tmp = va_arg(i->va, char *);
	i->tmp = (i->tmp != NULL ? ft_strdup(i->tmp) : NULL);
	(i->tmp == NULL ? print_null(i) : print_string(i));
}