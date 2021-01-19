/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:01:44 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/19 14:33:51 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_weird_c(int c)
{
	return (c);
}

int	ft_get_c(int c)
{
	int	i;

	i = 0;
	if (p_list.flag == '*')
		while (i++ < p_list.prec1 - 1)
			write(1, " ", 1);
	else if (p_list.flag == '0')
		while (i++ < p_list.prec1 - 1)
			write(1, "0", 1);
	ft_putchar_fd(c, 1);
	if (p_list.flag == '-')
		while (i++ < p_list.prec1 - 1)
			write(1, " ", 1);
	return (p_list.prec1 ? p_list.prec1 : 1);
}
