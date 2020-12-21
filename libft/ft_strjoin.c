/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:47:51 by ctirions          #+#    #+#             */
/*   Updated: 2020/11/23 13:38:55 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*pt;

	if (!s1)
		return (0);
	if (!(pt = malloc(sizeof(char) * \
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		pt[i] = s1[i];
	i -= 1;
	while (s2[++i - ft_strlen(s1)])
		pt[i] = s2[i - ft_strlen(s1)];
	pt[i] = 0;
	return (pt);
}
