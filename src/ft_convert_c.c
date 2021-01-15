/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:01:44 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/15 15:23:50 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_c(int c)
{
	int	i;

	i = -1;
	if (p_list.flag == '.' && p_list.prec1)
		return (-1);
	if (p_list.point && p_list.prec2)
		return (-1);
	if (p_list.flag == '*')
		while (++i < p_list.prec1 - 1)
			write(1, " ", 1);
	ft_putchar_fd(c, 1);
	if (p_list.flag == '-')
	{
		while (++i < p_list.prec1 - 1)
			write(1, " ", 1);
	}
	return (p_list.prec1 ? p_list.prec1 : 1);
}
