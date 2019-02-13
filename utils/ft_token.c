/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:11:14 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/17 17:44:13 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_token.h"

t_token	*ft_tok_init(int pos)
{
	t_token	*res;

	if (!(res = (t_token *)malloc(sizeof(*res))))
		return (NULL);
	res->conv = 0;
	res->flag = 0;
	res->pos = pos;
	return (res);
}

t_token	*ft_tok_setf(t_token *tok, t_flag f)
{
	if (!tok)
		return (NULL);

	tok->flag |= 1 << f;
	return (tok);
}

t_token	*ft_tok_setc(t_token *tok, t_conv c)
{
	if (!tok)
		return (NULL);

	tok->conv |= 1 << c;
	return (tok);
}