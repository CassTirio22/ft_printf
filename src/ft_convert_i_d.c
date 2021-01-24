/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:55:53 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/24 13:20:39 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_flag_bef(int size, int neg)
{
	int i;

	i = 0;
	if (p_list.flag == '*')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	if (neg)
		ft_putchar_fd('-', 1);
	if (p_list.flag == '0')
		while (i++ < p_list.prec1 - size)
			write(1, "0", 1);
	return (i);
}

static int	ft_weird_i_d(unsigned int n, int k, int i, int neg)
{
	int size;
	int	j;

	size = p_list.point ? p_list.prec2 : p_list.prec1;
	size = size > ft_count(n) ? size : ft_count(n);
	i += k;
	j = 0;
	if (p_list.flag == '*' || p_list.flag == '0')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	if (neg)
		ft_putchar_fd('-', 1);
	while (j++ < size - ft_count(n))
		write(1, "0", 1);
	ft_put_unsigned_int(n);
	if (p_list.flag == '-')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	return (i ? size + i - 1 : size);
}

int			ft_get_i_d(int n, int size, int neg)
{
	int				i;
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = -n;
		size++;
		neg++;
	}
	else
		nbr = n;
	if (p_list.flag == '.' || p_list.point)
		return (ft_weird_i_d(nbr, size, 0, neg));
	size += ft_count(nbr);
	i = ft_flag_bef(size, neg);
	ft_put_unsigned_int(nbr);
	if (p_list.flag == '-')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	return (i ? size + i - 1 : size);
}
