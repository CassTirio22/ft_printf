/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_capx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:42:41 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/17 20:18:22 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_flag_zero_all(int size)
{
	int i;

	i = 0;
	if (p_list.flag == '*')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	else if (p_list.flag == '0')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	return (i);
}

int			ft_weird_capx(unsigned int n, const char *hex, int power, char *res)
{
	int	size;
	int	i;
	int	j;

	size = p_list.point ? p_list.prec2 : p_list.prec1;
	size = size > power ? size : power;
	j = 0;
	i = ft_flag_zero_all(size);
	while (j++ < size - power)
		write(1, "0", 1);
	while (power--)
	{
		res[power] = hex[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	free(res);
	if (p_list.flag == '-')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	return (i ? size + i - 1 : size);
}

int			ft_get_capx(unsigned int n, int i)
{
	const char	*hex;
	int			power;
	int			size;
	char		*res;

	hex = "0123456789ABCDEF";
	power = ft_len_hex_nbr(n);
	size = power;
	if (!(res = (char *)ft_calloc(sizeof(char), power + 1)))
		return (0);
	if (p_list.flag == '.' || p_list.point)
		return (ft_weird_capx(n, hex, power, res));
	i = ft_flag_zero_all(size);
	while (power--)
	{
		res[power] = hex[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	free(res);
	if (p_list.flag == '-')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	return (i ? size + i - 1 : size);
}
