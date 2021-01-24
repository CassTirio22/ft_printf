/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:19:41 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/24 13:26:33 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_ajust_elem(void)
{
	if (p_list.flag && p_list.flag != '.' && p_list.prec1 < 0)
	{
		p_list.flag = '-';
		p_list.prec1 = -p_list.prec1;
	}
	if (p_list.flag == '.' && p_list.prec1 < 0)
	{
		p_list.flag = 0;
		p_list.prec1 = 0;
	}
	if (p_list.point && p_list.prec2 < 0)
	{
		p_list.point = 0;
		p_list.prec2 = 0;
	}
}

int			ft_get_element(const char **string)
{
	(*string)++;
	ft_set_element();
	p_list.flag = ft_get_first_flag(string);
	ft_get_first_precision(string);
	ft_get_second(string);
	ft_ajust_elem();
	p_list.res = ft_execute(string, "sicxXupd%", -1, "0123456789abcdef");
	if (p_list.error)
		return (-1);
	return (p_list.res);
}
