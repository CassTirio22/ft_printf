/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:02:00 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/07 19:39:32 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_get_x(unsigned int n)
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
