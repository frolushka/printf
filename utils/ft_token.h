/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:11:23 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/17 17:42:14 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H

# include <stdlib.h> 

typedef struct  s_token
{
	int         flag;
	int         conv;
    int         pos;
}               t_token;

typedef enum    e_flag
{
    NONE = 0
}               t_flag;

typedef enum    e_conv
{
    NONE = 0
}               t_conv;

t_token         *ft_tok_init(int pos);
t_token         *ft_tok_setf(t_token *tok, t_flag f);
t_token         *ft_tok_setc(t_token *tok, t_conv c);

#endif