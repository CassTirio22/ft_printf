/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:27:51 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/07 19:39:19 by ctirions         ###   ########.fr       */
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
