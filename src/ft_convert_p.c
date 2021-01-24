/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:21:25 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/24 14:30:29 by ctirions         ###   ########.fr       */
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

	j = 0;
	i = 0;
	size = p_list.point ? p_list.prec2 : p_list.prec1;
	size = size > power ? size : power;
	if (p_list.flag == '*' || p_list.flag == '0')
		while (i++ < p_list.prec1 - size - 2)
			write(1, " ", 1);
	write(1, "0x", 2);
	while (j++ < size - power)
		write(1, "0", 1);
	ft_putres(addr, power, hex, res);
	if (p_list.flag == '-')
		while (i++ < p_list.prec1 - size - 2)
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
	if (p_list.point || p_list.flag == '.')
		return (ft_weird_p(addr, power, hex, res));
	size = power;
	if (p_list.flag == '*')
		while (i++ < p_list.prec1 - size - 2)
			write(1, " ", 1);
	write(1, "0x", 2);
	if (p_list.flag == '0')
		while (i++ < p_list.prec1 - size - 2)
			write(1, "0", 1);
	ft_putres(addr, power, hex, res);
	if (p_list.flag == '-')
		while (i++ < p_list.prec1 - size - 2)
			write(1, " ", 1);
	i = i ? --i : i;
	return (size + 2 + i);
}
