/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_capx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:42:41 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/07 19:39:21 by ctirions         ###   ########.fr       */
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
