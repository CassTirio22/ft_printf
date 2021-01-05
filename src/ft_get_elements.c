
int	ft_get_precision(const char *string, va_list arg)
{
}

int	ft_get_percent(const char *string)
{
}

int	ft_get_flag(const char *string)
{
	char	*flags;
	int		i;

	flags = "-0.*";
	i = -1;
	if (ft_isdigit((int)*string))
		return (5);
	while (flags[++i])
	{
		if (*string == flags[i])
		{
			if (i == 0 || i == 1)
				while (*string == flags[i])
					string++;
			string++;
			return (++i);
		}
	}
	return (0);
}