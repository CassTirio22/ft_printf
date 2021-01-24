/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:26:07 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/24 13:26:47 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int d;
	int	*i;

	d = -27;
	i = &d;
	printf("%d\n", printf("|%0*p|\n", -7, i));
	printf("%d\n", ft_printf("|%0*p|\n", -7, i));
	return (0);
}
