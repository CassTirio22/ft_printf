/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:27:51 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/15 14:39:05 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_p(void *pt)
{
	unsigned long	addr;
	char			*hexa_base;
	char			*res;
	int				power;
	int				count;

	count = 0;
	addr = (unsigned long)pt;
	hexa_base = "0123456789abcdef";
	power = ft_len_hex_nbr(addr);
	if (!(res = (char *)ft_calloc(sizeof(char), power + 1)))
		return (0);
	write(1, "0x", 2);
	while (power--)
	{
		count++;
		res[power] = hexa_base[addr % 16];
		addr /= 16;
	}
	ft_putstr_fd(res, 1);
	free(res);
	return (count + 2);
}
