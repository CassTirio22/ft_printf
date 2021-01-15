/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:37:00 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/15 14:36:20 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_u(int n)
{
	unsigned int	nbr;
	
	if (n < 0)
		nbr = UINT_MAX + n + 1;
	else
		nbr = n;
	ft_putnbr_fd(nbr, 1);
	return (ft_count(nbr));
}
