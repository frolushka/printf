/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_convers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 01:30:26 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/09 17:35:32 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_spec_2(t_info *i, char const *f)
{
// 	if (ft_strchr(HEX, f[i->ind]))
// 		spec_base(i);
// 	else if (f[i->ind] == 'n')
// 		spec_return(i);
// 	else if (f[i->ind] == 'p' || f[i->ind] == 'P')
// 		spec_ptraddr(i, f[i->ind]);
// 	else if (f[i->ind] == 'r')
// 		spec_non_printable(i);
// 	else if (f[i->ind] == 'w')
// 		spec_fd(i);
// 	else if (f[i->ind] != '\0')
// 		print_invalid_spec(e, fmt[e->i]);
}

void		set_spec(t_info *i, char const *f)
{
	if (f[i->ind] == '%')
		print_percent(i);
	else if (f[i->ind] == 'c')
		prep_char(i);
	else if (f[i->ind] == 'C')
		prep_wchar(i);
	else if (f[i->ind] == 's')
		prep_string(i);
	else if (f[i->ind] == 'S')
	 	prep_wstring(i);
	else if (f[i->ind] == 'p' || f[i->ind] == 'P')
	{
		(f[i->ind] == 'P' ? i->cfs |= FLAG_up : 0);
		prep_address(i);
	}
	else if (f[i->ind] == 'd' || f[i->ind] == 'D' || f[i->ind] == 'i')
	{
		(f[i->ind] == 'D' ? i->cfs |= FLAG_l : 0);
		prep_number(i);
	}
	else if (f[i->ind] == 'o' || f[i->ind] == 'O')
	{
		i->bas = 8;
		(f[i->ind] == 'O' ? i->cfs |= FLAG_l : 0);
		prep_unumber(i);
	}
	else if (f[i->ind] == 'u' || f[i->ind] == 'U')
	{
		i->bas = 10;
		(f[i->ind] == 'U' ? i->cfs |= FLAG_l : 0);
		prep_unumber(i);
	}
	else if (f[i->ind] == 'x' || f[i->ind] == 'X')
	{
		i->bas = 16;
		(f[i->ind] == 'X' ? i->cfs |= FLAG_up : 0);
		prep_unumber(i);
	}
	else if (f[i->ind] == 'b' || f[i->ind] == 'B')
	{
		i->bas = 2;
		(f[i->ind] == 'B' ? i->cfs |= FLAG_up : 0);
		prep_unumber(i);
	}
	// else if ((f[i->ind] == 'd' || f[i->ind] == 'i') && !(i->cfs & FLAG_z))
	// 	spec_int(i);
	// else if ((f[i->ind] == 'u' || f[i->ind] == 'U' || f[i->ind] == 'd' ||
	// 		f[i->ind] == 'D' || f[i->ind] == 'i') && i->cfs & FLAG_z)
	// 	spec_uint(i);
	// else if (f[i->ind] == 'C' || f[i->ind] == 'S')
	// 	spec_char(i);
	// else if ((f[i->ind] == 'c' || f[i->ind] == 's') && i->cfs && FLAG_l)
	// 	spec_wchar(i);
	// else if (ft_strchr(PREC, f[i->ind]))
	// 	spec_precision(i);
	else
		set_spec_2(i, f);
}