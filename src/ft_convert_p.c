/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:27:51 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/16 15:12:31 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_p(void *pt)
{
	unsigned long	addr;
	char			*hexa_base;
	int				power;
	int				count;

	count = 0;
	addr = (unsigned long)pt;
	hexa_base = "0123456789abcdef";
	power = ft_len_hex_nbr(addr);
	write(1, "0x", 2);
	while (power--)
	{
		count++;
		ft_putchar_fd(hexa_base[addr % 16], 1);
		addr /= 16;
	}
	return (count + 2);
}
