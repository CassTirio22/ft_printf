
#include "../ft_printf.h"

int	ft_check_flags_error2(const char c, const char flag)
{
	if (flag == '-')
		;
	else if (flag == '0')
		;
	else if (flag == '.')
		;
	else if (flag == '*')
		;
	return (0);
}

int	ft_check_flags_error(const char **string)
{
	const char	c;
	const char	flag;

	while (**string)
	{
		if (**string == '%')
		{
			c = ft_getpercent(string);
			flag = ft_getflag(string);
			if (ft_check_flags_error2(c, flag))
				return (1);
		}
		(*string)++;
	}
	return (0);
}

int	ft_check_percent_error(const char **string, va_list arg)
{

}

int	ft_check_error(const char *string, va_list arg)
{
	char	*string_bis;
	va_list	arg_bis;

	string_bis = ft_strdup(string);
	va_copy(arg_bis, arg);
	if (ft_check_flags_error(&string_bis, arg_bis))
		return (1);
	if (ft_check_percent_error(&string_bis, arg_bis))
		return (1);
	return (0);
}