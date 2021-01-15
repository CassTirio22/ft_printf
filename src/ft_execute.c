/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:55:21 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/15 15:30:31 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_get_element(const char **string)
{
	(*string)++;
	ft_set_element();
	p_list.flag = ft_get_first_flag(string);
	ft_get_first_precision(string);
	ft_get_second(string);
	ft_execute(string);
	if (p_list.error)
	{
		printf("ERROR\n");
		return (-1);
	}
	//printf("\nFLAG1 : %c\nPOINT : %d\nPREC1 : %d\nPREC2 : %d\n\n", p_list.flag, p_list.point, p_list.prec1, p_list.prec2);
	return (0);
}
