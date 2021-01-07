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
