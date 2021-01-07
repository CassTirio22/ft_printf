/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:01:44 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/07 19:39:22 by ctirions         ###   ########.fr       */
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
