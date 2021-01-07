/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:21:57 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/07 14:57:25 by ctirions         ###   ########.fr       */
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
