/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_capx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:21:12 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/04 11:24:41 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_get_capx(unsigned int n)
{
	char	*hexa_base;
	int		power;
	char	*res;

	hexa_base = "0123456789ABCDEF";
	power = ft_len_hex_nbr(n);
	if (!(res = ft_calloc(sizeof(char), (power + 1))))
		return (0);
	while (power--)
	{
		res[power] = hexa_base[n % 16];
		n /= 16;
	}
	return (res);
}
