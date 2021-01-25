/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:22:51 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/25 17:35:47 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_weird_u(unsigned int nbr, int l)
{
	int	size;
	int	i;
	int	j;

	size = g_point ? g_prec2 : g_prec1;
	l = !nbr && !size ? 1 : 0;
	size = size > ft_count(nbr) ? size : ft_count(nbr);
	i = 0;
	j = 0;
	if (g_flag == '*')
		while (-l + i++ < g_prec1 - size)
			write(1, " ", 1);
	else if (g_flag == '0')
		while (-l + i++ < g_prec1 - size)
			write(1, " ", 1);
	while (j++ < size - ft_count(nbr))
		write(1, "0", 1);
	l ? size-- : ft_put_unsigned_int(nbr);
	if (g_flag == '-')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	return (i ? size + i - 1 : size);
}

int			ft_get_u(int n)
{
	unsigned int	nbr;
	int				size;
	int				i;

	if (n < 0)
		nbr = UINT_MAX + n + 1;
	else
		nbr = n;
	if (g_flag == '.' || g_point)
		return (ft_weird_u(nbr, 0));
	size = ft_count(nbr);
	i = 0;
	if (g_flag == '*')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	else if (g_flag == '0')
		while (i++ < g_prec1 - size)
			write(1, "0", 1);
	ft_put_unsigned_int(nbr);
	if (g_flag == '-')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	return (i ? size + i - 1 : size);
}
