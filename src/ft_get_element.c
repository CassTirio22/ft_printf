#include "../ft_printf.h"

char	ft_get_first_flag(const char **string)
{
	char	*flags;
	int		i;

	i = -1;
	flags = "-0.*";
	if (ft_isdigit((int)**string))
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
	int	i;

	if (!p_list.flag || !(**string == '.'))
	{
		if (!(**string == '.'))
			p_list.error = 1;
		return ;
	}
	p_list.point = 1;
	(*string)++;
	if (!ft_strchr(".*sicxXupd%", (int)**string) && !ft_isdigit((int)**string))
	{
		p_list.error = 1;
		return ;
	}
	else if (**string == '*')
	{
		p_list.precision2 = va_arg(p_list.arg, int);
		(*string)++;
	}
	else if (ft_isdigit((int)**string))
	{
		p_list.precision2 = ft_atoi(*string);
		i = ft_count(p_list.precision1);
		while (i--)
			(*string)++;
	}
}

/*void	ft_get_value(const char *string)
{
}*/