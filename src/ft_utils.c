/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:22:17 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/24 18:58:31 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_len_hex_nbr(unsigned long n)
{
	if (n < 16)
		return (1);
	return (1 + ft_len_hex_nbr(n / 16));
}

void	ft_put_unsigned_int(unsigned int n)
{
	if (n > 9)
		ft_put_unsigned_int(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

int		ft_atoi2(const char **str)
{
	int					i;
	int					neg;
	unsigned long long	res;
	unsigned long long	res_2;

	neg = 1;
	i = 0;
	res = 0;
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		(*str)++;
	if (**str == '+' || **str == '-')
		if (*(*str)++ == '-')
			neg *= -1;
	while (**str >= '0' && **str <= '9')
	{
		res_2 = res;
		res = res * 10 + *(*str)++ - '0';
		if (res > LLONG_MAX || res < res_2)
			return (neg == 1 ? -1 : 0);
	}
	return ((int)(neg * res));
}

int		ft_count(unsigned int n)
{
	int count;

	count = 0;
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (++count);
}
