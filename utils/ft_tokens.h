/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:05:18 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/17 18:13:37 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKENS_H
# define FT_TOKENS_H

# include "libft.h"

t_list	*ft_toks_get(char const *src);
char	*ft_toks_parse(char const *src, t_list *toks);

#endif