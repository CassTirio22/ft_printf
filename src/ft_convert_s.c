/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:22:09 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/24 13:27:03 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_flag_zero_all(int size)
{
	int	i;

	i = 0;
	if (p_list.flag == '*')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	else if (p_list.flag == '0')
		while (i++ < p_list.prec1 - size)
			write(1, "0", 1);
	return (i);
}

static int	ft_weird_s(char *str, char *str2)
{
	int		size;
	int		size2;
	int		i;
	int		j;

	size = p_list.point ? p_list.prec2 : p_list.prec1;
	size2 = !str ? 6 : ft_strlen(str);
	size = size > size2 ? size2 : size;
	i = 0;
	j = ft_flag_zero_all(size);
	if (!str)
		while (str2[i] && i < size)
			ft_putchar_fd(str2[i++], 1);
	else
		while (str[i] && i < size)
			ft_putchar_fd(str[i++], 1);
	if (p_list.flag == '-')
		while (j++ < p_list.prec1 - size)
			write(1, " ", 1);
	j = j ? --j : j;
	return (size + j);
}

int			ft_get_s(char *str)
{
	int	size;
	int	i;

	if (p_list.flag == '.' || p_list.point)
		return (ft_weird_s(str, "(null)"));
	size = !str ? 6 : ft_strlen(str);
	i = ft_flag_zero_all(size);
	if (!str)
		write(1, "(null)", 6);
	else
		ft_putstr_fd(str, 1);
	if (p_list.flag == '-')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	i = i ? --i : i;
	return (!str ? 6 + i : ft_strlen(str) + i);
}
