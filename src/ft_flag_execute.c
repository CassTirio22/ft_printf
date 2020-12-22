/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:15:20 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/22 15:35:03 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_flag_minus(const char **string, va_list arg)
{
	int res;
	int spaces;
	int i;

	spaces = 0;
	res = 0;
	(*string)++;
	if (**string == '*')
	{
		(*string)++;
		spaces = va_arg(arg, int);
	}
	else if (ft_isdigit((int)**string))
	{
		spaces = ft_atoi((const char *)(*string));
		i = ft_count(spaces);
		while (res++ < i)
			(*string)++;
		res = 0;
	}
	res += ft_percent(string, arg);
	i = -1;
	while (spaces > res + ++i)
		write(1, " ", 1);
	return (res + i);
}

int	ft_flag_zero_point(const char **string, va_list arg, int zeros)
{
	va_list arg_2;
	int		res;
	int		i;

	res = 0;
	(*string)++;
	if (**string == '*')
	{
		(*string)++;
		zeros = va_arg(arg, int);
	}
	else if (ft_isdigit((int)**string))
	{
		zeros = ft_atoi((const char *)(*string));
		i = ft_count(zeros);
		while (res++ < i)
			(*string)++;
	}
	va_copy(arg_2, arg);
	res = ft_len_arg(string, arg_2);
	i = -1;
	while (zeros > res + ++i)
		write (1, "0", 1);
	ft_percent(string, arg);
	return (res + i);
}

int	ft_flag_nbr_all(const char **string, va_list arg, int all)
{
	va_list arg_2;
	int		res;
	int		i;

	res = 0;
	if (**string == '*')
	{
		(*string)++;
		all = va_arg(arg, int);
	}
	else if (ft_isdigit((int)**string))
	{
		all = ft_atoi((const char *)(*string));
		i = ft_count(all);
		while (res++ < i)
			(*string)++;
	}
	va_copy(arg_2, arg);
	res = ft_len_arg(string, arg_2);
	i = -1;
	while (all > res + ++i)
		write (1, " ", 1);
	ft_percent(string, arg);
	return (res + i);
}
