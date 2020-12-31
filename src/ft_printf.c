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

int	ft_percent(const char **string, va_list arg)
{
	if (**string == 's')
		return (ft_convert_s(va_arg(arg, char *)));
	else if (**string == 'i' || **string == 'd')
		return (ft_convert_i_d(va_arg(arg, unsigned int)));
	else if (**string == 'c')
		return (ft_convert_c(va_arg(arg, int)));
	else if (**string == 'x')
		return (ft_convert_x(va_arg(arg, unsigned int)));
	else if (**string == 'X')
		return (ft_convert_majx(va_arg(arg, unsigned int)));
	else if (**string == 'u')
		return (ft_convert_u(va_arg(arg, int)));
	else if (**string == 'p')
		return (ft_convert_p(va_arg(arg, void *)));
	else if (**string == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_get_flag(const char **string)
{
	char	*flags;
	int		i;

	flags = "-0.*";
	i = -1;
	if (ft_isdigit((int)**string))
		return (5);
	while (flags[++i])
		if (string == flags[i])
		{
			if (i == 0 || i == 1)
				while (string == flags[i])
					(*string)++;
			return (i++);
		}
	return (0);
}

int	ft_check_flag(const char **string, va_list arg)
{
	int	i;
	int	res;

	res = 0;
	(*string)++;
	i = ft_get_flag(string);
	if (!ft_strchr(".*sicxXupd%", (int)**string) || !ft_isdigit((int)**string))
		return (-1);
	if (!i)
		return (ft_percent(string, arg));
}

int	ft_printf(const char *string, ...)
{
	va_list	arg;
	int		res;
	int		tmp;

	if (!string)
		return (0);
	va_start(arg, string);
	res = 0;
	while (*string)
	{
		if (!(*string == '%'))
		{
			res++;
			write(1, string, 1);
		}
		else
		{
			if ((tmp = ft_check_flag(&string, arg)) == -1)
				return (res);
			res += tmp;
		}
		string++;
	}
	va_end(arg);
	return (res);
}
