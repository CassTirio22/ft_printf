/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:21:39 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/10 13:04:27 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_get_p(void *pt)
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
	if (!(res = ft_calloc(sizeof(char), (power + 3))))
		return (0);
	res[0] = '0';
	res[1] = 'x';
	while (power-- > 2)
	{
		count++;
		res[power] = hexa_base[addr % 16];
		addr /= 16;
	}
	return (res);
}
