/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:02:00 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/16 15:12:44 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_x(unsigned int n)
{
	char	*hexa_base;
	int		power;
	int		count;

	hexa_base = "0123456789abcdef";
	power = ft_len_hex_nbr(n);
	count = power;
	while (power--)
	{
		ft_putchar_fd(hexa_base[n % 16], 1);
		n /= 16;
	}
	return (count);
}
