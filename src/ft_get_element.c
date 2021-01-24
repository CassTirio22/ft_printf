/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:26:46 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/24 19:09:09 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	ft_get_first_flag(const char **string)
{
	char	*flags;
	int		i;

	i = -1;
	flags = "-0.";
	if ((ft_isdigit((int)**string) && **string != '0') || **string == '*')
		return ('*');
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
	if (!ft_strchr(".*sicxXupd%", (int)**string) &&\
		!ft_isdigit((int)**string) && **string != '-')
	{
		p_list.error = 1;
		return ;
	}
	else if (**string == '*')
	{
		p_list.prec1 = va_arg(p_list.arg, int);
		(*string)++;
	}
	else if (ft_isdigit((int)**string) || **string == '-')
		p_list.prec1 = ft_atoi2(string);
}

void	ft_get_second(const char **string)
{
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
		p_list.prec2 = va_arg(p_list.arg, int);
		(*string)++;
	}
	else if (ft_isdigit((int)**string))
		p_list.prec2 = ft_atoi2(string);
}

int		ft_execute(const char **string, char *percent_str, int i, char *hex)
{
	while (percent_str[++i])
	{
		if (**string == percent_str[i])
		{
			if (i == 0)
				return (ft_get_s(va_arg(p_list.arg, char *)));
			else if (i == 1 || i == 7)
				return (ft_get_i_d(va_arg(p_list.arg, int), 0, 0));
			else if (i == 2)
				return (ft_get_c(va_arg(p_list.arg, int)));
			else if (i == 3)
				return (ft_get_x(va_arg(p_list.arg, unsigned int), hex));
			else if (i == 4)
				return (ft_get_x(va_arg(p_list.arg, unsigned int),\
					"0123456789ABCDEF"));
			else if (i == 5)
				return (ft_get_u(va_arg(p_list.arg, int)));
			if (i == 6)
				return (ft_get_p(va_arg(p_list.arg, void *), hex, 0));
			return (ft_get_c('%'));
		}
	}
	p_list.error = 1;
	return (0);
}
