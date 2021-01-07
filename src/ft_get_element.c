/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:36:11 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/07 19:39:39 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	ft_get_first_flag(const char **string)
{
	char	*flags;
	int		i;

	i = -1;
	flags = "-0.*";
	if (ft_isdigit((int)**string) && **string != '0')
		return ('n');
	while (flags[++i])
	{
		if (**string == flags[i])
		{
			(*string)++;
			if (i == 0 || i == 1)
				while (**string == flags[i])
					(*string)++;
			return (flags[i]);
		}
	}
	return (0);
}

void	ft_get_first_precision(const char **string)
{
	int	i;

	if (!ft_strchr(".*sicxXupd%", (int)**string) && !ft_isdigit((int)**string))
	{
		p_list.error = 1;
		return ;
	}
	else if (**string == '*')
	{
		p_list.precision1 = va_arg(p_list.arg, int);
		(*string)++;
	}
	else if (ft_isdigit((int)**string))
	{
		p_list.precision1 = ft_atoi(*string);
		i = ft_count(p_list.precision1);
		while (i--)
			(*string)++;
	}
}

void	ft_get_second(const char **string)
{
	int i;

	if (ft_strchr("sicxXupd%", (int)**string))
		return ;
	else if (**string != '.')
	{
		p_list.error = 1;
		return ;
	}
	p_list.point = 1;
	(*string)++;
	if (**string == '*')
	{
		p_list.precision2 = va_arg(p_list.arg, int);
		(*string)++;
	}
	else if (ft_isdigit((int)**string))
	{
		p_list.precision2 = ft_atoi(*string);
		i = ft_count(p_list.precision2);
		while (i--)
			(*string)++;
	}
}

char	*ft_get_value(const char **string)
{
	const char	*percent_str;
	int			i;

	i = -1;
	percent_str = "sicxXupd";
	while (percent_str[++i])
	{
		if (**string == percent_str[i])
		{
			(*string)++;
			if (i == 0)
				return (ft_get_s(va_arg(p_list.arg, char *)));
			else if (i == 1 || i == 7)
				return (ft_get_i_d(va_arg(p_list.arg, int)));
			else if (i == 2)
				return (ft_get_c(va_arg(p_list.arg, int)));
			else if (i == 3)
				return (ft_get_x(va_arg(p_list.arg, unsigned int)));
			else if (i == 4)
				return (ft_get_capx(va_arg(p_list.arg, unsigned int)));
			else if (i == 5)
				return (ft_get_u(va_arg(p_list.arg, int)));
			return (ft_get_p(va_arg(p_list.arg, void *)));
		}
	}
	p_list.error = 1;
	return (NULL);
}
