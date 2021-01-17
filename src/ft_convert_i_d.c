/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:55:53 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/17 19:52:06 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_weird_i_d(int n)
{
	int	size;
	int	i;
	int	j;

	size = p_list.point ? p_list.prec2 : p_list.prec1;
	size = size > ft_count(n) ? size : ft_count(n);
	i = 0;
	j = 0;
	if (p_list.flag == '*')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	else if (p_list.flag == '0')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	while (j++ < size - ft_count(n))
		write(1, "0", 1);
	ft_putnbr_fd(n, 1);
	if (p_list.flag == '-')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	return (i ? size + i - 1 : size);
}

int	ft_get_i_d(int n)
{
	int	size;
	int	i;

	if (p_list.flag == '.' || p_list.point)
		return (ft_weird_i_d(n));
	size = ft_count(n);
	i = 0;
	if (p_list.flag == '*')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	else if (p_list.flag == '0')
		while (i++ < p_list.prec1 - size)
			write(1, "0", 1);
	ft_putnbr_fd(n, 1);
	if (p_list.flag == '-')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	return (i ? size + i - 1 : size);
}
