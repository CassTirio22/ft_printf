/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:48:27 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/17 16:17:42 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_weird_s(char *str)
{
	int		size;
	int		i;
	int		j;
	char	*str2;

	str2 = "(null)";
	j = 0;
	size = p_list.point ? p_list.prec2 : p_list.prec1;
	if (p_list.flag == '*')
		while (j++ < p_list.prec1 - size)
			write(1, " ", 1);
	i = 0;
	if (!str)
		while (str2[i] && i < size)
			ft_putchar_fd(str2[i++], 1);
	else
		while (str[i] && i < size)
			ft_putchar_fd(str[i++], 1);
	if (p_list.flag == '-')
		while (j++ < p_list.prec1 - size)
			write(1, " ", 1);
	j = j ? j-- : j;
	return (ft_strlen(str) > (size_t)size ? size + j : ft_strlen(str));
}

int	ft_get_s(char *str)
{
	int	size;
	int	i;

	if (p_list.flag == '.' || p_list.point)
		return (ft_weird_s(str));
	size = !str ? 6 : ft_strlen(str);
	i = 0;
	if (p_list.flag == '*')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	if (!str)
		write(1, "(null)", 6);
	else
		ft_putstr_fd(str, 1);
	if (p_list.flag == '-')
		while (i++ < p_list.prec1 - size)
			write(1, " ", 1);
	i = i ? i-- : i;
	return (!str ? 6 + i : ft_strlen(str) + i);
}
