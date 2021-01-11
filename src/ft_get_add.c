/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:17:17 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/11 16:00:18 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_flag_minus(void)
{
}

char	*ft_flag_zero(void)
{
}

char	*ft_flag_point(void)
{
	if (p_list.percent == 's')
		return (NULL);
}

char	*ft_flag_nbr(void)
{
}

char	*ft_get_add(void)
{
	char	*res;

	if (p_list.flag == '-')
		res = ft_flag_minus();
	else if (p_list.flag == '0')
		res = ft_flag_zero();
	else if (p_list.flag == '.')
		res = ft_flag_point();
	else
		res = ft_flag_nbr();
	return (res);
}