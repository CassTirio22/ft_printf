/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:22:12 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/04 15:41:57 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_convert_u(int n)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	if (n < 0)
	{
		nbr = UINT_MAX + n + 1;
		ft_put_unsigned_int(nbr);
		return (ft_count(nbr));
	}
	ft_putnbr_fd(n, 1);
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (count);
}
