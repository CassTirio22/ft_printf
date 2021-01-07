/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:20:41 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/04 12:20:08 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_get_c(int c)
{
	char	*str;

	p_list.percent = 'c';
	if (!(str = (char *)malloc(sizeof(char))))
		return (0);
	str[0] = (char)c;
	return (str);
}
