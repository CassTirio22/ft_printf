/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:09:30 by ctirions          #+#    #+#             */
/*   Updated: 2020/11/23 13:37:59 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (!s)
		return (0);
	i = -1;
	if (!(res = ft_calloc(sizeof(char), ft_strlen(s) + 1)))
		return (0);
	if (s && f)
		while (++i < ft_strlen(s))
			res[i] = f(i, s[i]);
	return (res);
}
