/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:22:26 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/04 11:24:32 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_convert_x(unsigned int n)
{
	char	*hexa_base;
	int		power;
	char	*res;

	hexa_base = "0123456789abcdef";
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
