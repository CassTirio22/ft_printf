/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:21:25 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/06 12:27:31 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putres(unsigned long addr, int power, char *hex, char *res)
{
	while (power--)
	{
		res[power] = hex[addr % 16];
		addr /= 16;
	}
	ft_putstr_fd(res, 1);
	free(res);
}

static int	ft_weird_p(unsigned long addr, int power, char *hex, char *res)
{
	int	size;
	int	i;
	int	j;
	int	l;

	j = 0;
	i = 0;
	size = g_point ? g_prec2 : g_prec1;
	l = !size && !addr ? 1 : 0;
	size = size > power ? size : power;
	if (g_flag == '*' || g_flag == '0')
		while (i++ < g_prec1 - size - 2 + l)
			write(1, " ", 1);
	write(1, "0x", 2);
	while (j++ < size - power)
		write(1, "0", 1);
	l ? size-- : ft_putres(addr, power, hex, res);
	if (g_flag == '-')
		while (i++ < g_prec1 - size - 2)
			write(1, " ", 1);
	i = i ? --i : i;
	return (size + 2 + i);
}

int			ft_get_p(void *pt, char *hex, int i)
{
	unsigned long	addr;
	int				power;
	int				size;
	char			*res;

	addr = (unsigned long)pt;
	power = ft_len_hex_nbr(addr);
	if (!(res = (char *)ft_calloc(sizeof(char), power + 1)))
		return (0);
	if (g_point || g_flag == '.')
		return (ft_weird_p(addr, power, hex, res));
	size = power;
	if (g_flag == '*')
		while (i++ < g_prec1 - size - 2)
			write(1, " ", 1);
	write(1, "0x", 2);
	if (g_flag == '0')
		while (i++ < g_prec1 - size - 2)
			write(1, "0", 1);
	ft_putres(addr, power, hex, res);
	if (g_flag == '-')
		while (i++ < g_prec1 - size - 2)
			write(1, " ", 1);
	i = i ? --i : i;
	return (size + 2 + i);
}
