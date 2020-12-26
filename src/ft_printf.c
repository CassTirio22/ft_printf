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

int	ft_check_flag(const char **string, va_list arg)
{
	int	i;

	(*string)++;
	i  = ft_is_whitespace(string);
	if ((**string - i - 1) == '-')
	{
		return (ft_flag_minus(string, arg) + i);
	}
	else if (**string == '0' || **string == '.')
	{
		return (ft_flag_zero_point(string, arg, 0) + i);
	}
	else if (**string == '*' || ft_isdigit((int)**string))
	{
		return (ft_flag_nbr_all(string, arg, 0) + i);
	}
	return (ft_percent(string, arg) + i);
}

int	ft_printf(const char *string, ...)
{
	va_list	arg;
	int		res;

	va_start(arg, string);
	if (ft_check_error(arg, string))
		return (0);
	res = 0;
	while (*string)
	{
		if (!(*string == '%'))
		{
			res++;
			write(1, string, 1);
		}
		else
			res += ft_check_flag(&string, arg);
		string++;
	}
	va_end(arg);
	return (res);
}
