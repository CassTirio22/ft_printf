/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:48:27 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/15 14:41:45 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_weird_s(void)
{
	return (0);
}

int	ft_get_s(char *str)
{
	if (p_list.flag == '.' || p_list.point)
		return (ft_weird_s());
	if (!str)
		write(1, "(null)", 6);
	else
		ft_putstr_fd(str, 1);
	return (!str ? 6 : ft_strlen(str));
}
