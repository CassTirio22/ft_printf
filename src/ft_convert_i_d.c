/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:55:53 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/07 19:39:20 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_get_i_d(int n)
{
	unsigned int	nbr;

	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	return (ft_itoa(nbr));
}
