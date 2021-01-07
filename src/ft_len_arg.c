/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:38:48 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/07 19:39:42 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_len_i_d(int n)
{
	unsigned int	nbr;
	int				count;

	count = 0;
	if (n < 0)
	{
		count++;
		nbr = -n;
	}
	else
		nbr = n;
	while (nbr > 9)
	{
		count++;
		nbr /= 10;
	}
	return (++count);
}

static int	ft_len_p(void *pt)
{
	unsigned int	addr;

	addr = (unsigned int)pt;
	return (ft_len_hex_nbr(addr) + 2);
}

int			ft_len_arg(const char *string, va_list arg)
{
	if (*string == 'x' || *string == 'X')
		return (ft_len_hex_nbr(va_arg(arg, unsigned int)));
	else if (*string == 'd' || *string == 'i')
		return (ft_len_i_d(va_arg(arg, int)));
	else if (*string == 'p')
		return (ft_len_p(va_arg(arg, void *)));
	else if (*string == 'c')
		return (1);
	else if (*string == 's')
		return (ft_strlen(va_arg(arg, char *)));
	else if (*string == 'u')
		return (ft_count(va_arg(arg, unsigned int)));
	return (0);
}
