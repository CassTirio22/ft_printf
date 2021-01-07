/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:48:27 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/07 19:39:19 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_get_s(char *str)
{
	char	*res;
	p_list.percent = 's';
	if (!str)
	{
		if (!(res = (char *)ft_calloc(sizeof(char), 7)))
			return (NULL);
		res = "(null)";
	}
	else
	{
		if (!(res = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1)))
			return (NULL);
		res = str;
	}
	return (res);
}
