/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:40:51 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/10 14:58:19 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_itoa_count(long long int n)
{
	int				count;
	unsigned int	nb;

	count = 0;
	if (n < 0)
	{
		count++;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		count++;
		nb /= 10;
	}
	return (++count);
}

char				*ft_itoa(long long int n)
{
	int				count;
	char			*res;
	unsigned int	nb;

	count = (n) ? ft_itoa_count(n) : 1;
	if (!(res = ft_calloc(sizeof(char), count + 1)))
		return (0);
	if (!n)
	{
		res[0] = '0';
		return (res);
	}
	nb = (n < 0) ? -n : n;
	while (count)
	{
		res[count - 1] = nb % 10 + '0';
		if (!(count - 1) && !nb)
			res[count - 1] = '-';
		nb /= 10;
		count--;
	}
	return (res);
}
