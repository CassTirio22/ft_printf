/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:21:30 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/26 15:49:05 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_c(int c)
{
	int	i;

	i = 0;
	if (g_flag == '*')
		while (i++ < g_prec1 - 1)
			write(1, " ", 1);
	else if (g_flag == '0')
		while (i++ < g_prec1 - 1)
			write(1, "0", 1);
	ft_putchar_fd(c, 1);
	if (g_flag == '-')
		while (i++ < g_prec1 - 1)
			write(1, " ", 1);
	return (g_prec1 && g_flag != '.' ? g_prec1 : 1);
}
