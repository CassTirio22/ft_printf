/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:20:55 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/04 11:25:44 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_convert_i_d(int n)
{
	int				count;
	unsigned int	nbr;

	ft_putnbr_fd(n, 1);
	count = 1;
	if (n < 0)
	{
		count++;
		nbr = -n;
	}
	else
		nbr = n;
	while (nbr > 9)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
