/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_majx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:21:12 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/04 11:24:41 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_convert_majx(unsigned int n)
{
	char	*hexa_base;
	int		power;
	char	*res;
	int		count;

	count = 0;
	hexa_base = "0123456789ABCDEF";
	power = ft_len_hex_nbr(n);
	if (!(res = ft_calloc(sizeof(char), (power + 1))))
		return (0);
	while (power--)
	{
		count++;
		res[power] = hexa_base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	return (count);
}
