/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_hex_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:00:12 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/08 12:13:16 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_len_hex_nbr(unsigned long n)
{
	if (n < 16)
		return (1);
	return (1 + ft_len_hex_nbr(n / 16));
}

void	ft_put_unsigned_int(unsigned int n)
{
	if (n > 9)
		ft_put_unsigned_int(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

int		ft_count(unsigned int n)
{
	int count;

	count = 0;
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (++count);
}
