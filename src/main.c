/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 00:47:10 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/08 16:37:52 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	// int a = printf("%% %s \t%s\n", NULL, "kek");
	// int b = ft_printf("%% %s \t%s\n", NULL, "kek");
	// printf("%d %d\n", a, b);
	// a = printf("%c \t%s\n", 'a', "kek");
	// b = ft_printf("%c \t%s\n", 'a', "kek");
	// printf("%d %d\n", a, b);
	// a = printf("%d\t%i\t%o\t%d\t%u\t%d\t%lld\t%lld\n", 0, -10, INT_MAX, INT_MIN, LONG_MIN, LONG_MAX);
	// b = ft_printf("%d\t%i\t%o\t%d\t%u\t%d\t%lld\t%lld\n", 0, -10, INT_MAX, INT_MIN, LONG_MIN, LONG_MAX);
	// 	printf("%d %d\n", a, b);
	// int a = ft_printf("42%.62s42\n", L"(null)");
	int b = ft_printf("@moulitest: %#.o %#.0o", 0, 0);
	// b = ft_printf("%lld\n", -9223372036854775808);
	// printf("%d %d\n", a, b);
	return (0);
}