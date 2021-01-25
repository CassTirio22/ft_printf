/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:23:20 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/25 17:37:00 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_flag_zero_all(int size, int l, int weird)
{
	int i;

	i = 0;
	if (g_flag == '*')
		while (-l + i++ < g_prec1 - size)
			write(1, " ", 1);
	else if (g_flag == '0')
		while (-l + i++ < g_prec1 - size)
			weird ? write(1, " ", 1) : write(1, "0", 1);
	return (i);
}

static int	ft_weird_x(unsigned int n, const char *hex, int power, char *res)
{
	int	size;
	int	i;
	int	l;
	int	j;

	size = g_point ? g_prec2 : g_prec1;
	l = !n && !size ? 1 : 0;
	size = size > power ? size : power;
	j = 0;
	i = ft_flag_zero_all(size, l, 1);
	while (j++ < size - power)
		write(1, "0", 1);
	while (power--)
	{
		res[power] = hex[n % 16];
		n /= 16;
	}
	l ? size-- : ft_putstr_fd(res, 1);
	free(res);
	if (g_flag == '-')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	return (i ? size + i - 1 : size);
}

int			ft_get_x(unsigned int n, const char *hex)
{
	int		i;
	int		power;
	int		size;
	char	*res;

	i = 0;
	power = ft_len_hex_nbr(n);
	size = power;
	if (!(res = (char *)ft_calloc(sizeof(char), power + 1)))
		return (0);
	if (g_flag == '.' || g_point)
		return (ft_weird_x(n, hex, power, res));
	i = ft_flag_zero_all(size, 0, 0);
	while (power--)
	{
		res[power] = hex[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	free(res);
	if (g_flag == '-')
		while (i++ < g_prec1 - size)
			write(1, " ", 1);
	return (i ? size + i - 1 : size);
}
