/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:37:00 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/18 14:41:06 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_weird_u(unsigned int nbr)
{
	int	size;
	int	i;
	int	j;

	size = p_list.point ? p_list.prec2 : p_list.prec1;
	size = size > ft_count(nbr) ? size : ft_count(nbr);
	i = 0;
	j = 0;
	if (p_list.flag == '*')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	else if (p_list.flag == '0')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	while (j++ < size - ft_count(nbr))
		write(1, "0", 1);
	ft_put_unsigned_int(nbr);
	if (p_list.flag == '-')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	return (i ? size + i - 1 : size);
}

int	ft_get_u(int n)
{
	unsigned int	nbr;
	int				size;
	int				i;

	if (n < 0)
		nbr = UINT_MAX + n + 1;
	else
		nbr = n;
	if (p_list.flag == '.' || p_list.point)
		return (ft_weird_u(nbr));
	size = ft_count(nbr);
	i = 0;
	if (p_list.flag == '*')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	else if (p_list.flag == '0')
		while (i++ < p_list.prec1 - size)
			write (1, "0", 1);
	ft_put_unsigned_int(nbr);
	if (p_list.flag == '-')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	return (i ? size + i - 1 : size);
}
