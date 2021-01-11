/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:55:21 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/11 15:17:36 by ctirions         ###   ########.fr       */
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
	p_list.value = ft_get_value(string);
	if (p_list.error || !p_list.value)
	{
		printf("ERROR\n");
		return (-1);
	}
	ft_execute();
	printf("FLAG1 : %c\nPOINT : %d\nPREC1 : %d\nPREC2 : %d\nVALUE : %s\n", p_list.flag, p_list.point, p_list.precision1, p_list.precision2, p_list.value);
	return (0);
}

char	*add_front(char *add)
{
	int		size;
	char	*res;

	size = ft_strlen(add) + ft_strlen(p_list.value);
	if (!(res = (char *)ft_calloc(sizeof(char), size + 1)))
		return (-1);
	while (size-- - ft_strlen(add))
		res[size] = p_list.value[size - ft_strlen(add)];
	while (size--)
		res[size] = add[size];
	free(p_list.value);
	return (res);
}

char	*add_back(char *add)
{
	int		size;
	char	*res;

	size = ft_strlen(add) + ft_strlen(p_list.value);
	if (!(res = (char *)ft_calloc(sizeof(char), size + 1)))
		return (-1);
	while (size-- - ft_strlen(p_list.value))
		res[size] = add[size - ft_strlen(p_list.value)];
	while (size--)
		res[size] = p_list.value[size];
	free(p_list.value);
	return (res);
}

void	ft_execute(void)
{
	if (p_list.point)
	{
		ft_convert_vlaue();
		if (p_list.flag == '*' || p_list.flag == '0')
			p_list.value = add_front(ft_get_add());
		else
			p_list.value = add_back(ft_get_add());
	}
	if (p_list.flag)
	{
		if (p_list.flag == '*' || p_list.flag == '0' || p_list.flag == '.')
			p_list.value = add_front(ft_get_add());
		else
			p_list.value = add_back(ft_get_add()); 
	}
}

/*int	ft_flag_minus(const char **string, va_list arg)
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
		write(1, "0", 1);
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
		write(1, " ", 1);
	ft_percent(string, arg);
	return (res + i);
}*/
