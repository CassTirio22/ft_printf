/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_hex_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:59:40 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/07 19:39:45 by ctirions         ###   ########.fr       */
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
