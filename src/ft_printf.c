/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:44:16 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/22 15:35:01 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_set_element(void)
{
	p_list.str = NULL;
	p_list.value = NULL;
	p_list.percent = '\0';
	p_list.flag = '\0';
	p_list.point = 0;
	p_list.precision1 = 0;
	p_list.precision2 = 0;
	p_list.res = 0;
	p_list.error = 0;
}

int		ft_printf(const char *string, ...)
{
	ft_set_element();
	if (!string)
		return (0);
	va_start(p_list.arg, string);
	while (*string)
	{
		if (!(*string == '%'))
		{
			p_list.res++;
			write(1, string, 1);
		}
		else
			if (ft_get_element(&string) == -1)
				return (p_list.res);
		string++;
	}
	va_end(p_list.arg);
	return (p_list.res);
}
