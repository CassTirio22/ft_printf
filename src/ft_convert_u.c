/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:37:00 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/07 19:39:17 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_get_u(int n)
{
	unsigned int	nbr;
	
	p_list.percent = 'u';
	if (n < 0)
	{
		nbr = UINT_MAX + n + 1;
		return (ft_itoa(nbr));
	}
	return (ft_itoa(n));
}
