/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 02:52:58 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/09 17:41:40 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void inline	set_mod(t_info *i, char const *f)
{
	if (f[i->ind] == 'h' && f[i->ind + 1] != 'h')
		i->cfs |= FLAG_h;
	else if (f[i->ind] == 'h' && f[i->ind + 1] == 'h')
	{
		i->cfs |= FLAG_hh;
		++i->ind;
	}
	if (f[i->ind] == 'l' && f[i->ind + 1] != 'l')
		i->cfs |= FLAG_l;
	else if (f[i->ind] == 'l' && f[i->ind + 1] == 'l')
	{
		i->cfs |= FLAG_ll;
		++i->ind;
	}
	else if (f[i->ind] == 'j')
		i->cfs |= FLAG_j;
	else if (f[i->ind] == 'z')
		i->cfs |= FLAG_z;
	else if (f[i->ind] == 'L')
		i->cfs |= FLAG_L;
}

static void inline	set_prec(t_info *i, char const *f)
{
	if (i->pre >= 0)
	{
		++i->ind;
		return ;
	}
	if (f[i->ind] == '.')
	{
		++i->ind;
		i->pre = ft_atoi(f + i->ind);
		while (ft_isdigit(f[i->ind]))
			++i->ind;
	}
}

void				set_flag(t_info *i, char const *f)
{
	while (ft_strchr(FLAGS, f[i->ind]))
	{
		(f[i->ind] >= 'L' && f[i->ind] <= 'z' ? set_mod(i, f) : 0);
		(f[i->ind] == '#') ? i->cfs |= FLAG_sharp : 0;
		(f[i->ind] == '0') ? i->cfs |= FLAG_zero : 0;
		(f[i->ind] == ' ') ? i->cfs |= FLAG_space : 0;
		(f[i->ind] == '-') ? i->cfs |= FLAG_minus : 0;
		(f[i->ind] == '+') ? i->cfs |= FLAG_plus : 0;
		if (f[i->ind] == '.')
			set_prec(i, f);
		else if (f[i->ind] >= '0' && f[i->ind] <= '9' && i->pre < 0)
		{
			i->wid = ft_atoi(f + i->ind);
			while (ft_isdigit(f[i->ind]))
				++i->ind;
		}
		else
			++i->ind;
	}
	if (i->pre != -1 || i->cfs & FLAG_minus)
		i->cfs &= ~FLAG_zero;
	if (i->cfs & FLAG_plus)
		i->cfs &= ~FLAG_space;
}