/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:31:55 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/19 19:56:30 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{	
	int d = -27;
	int	*i = &d;

	printf("%d\n", printf("|%14c|%015p|\n", 'c', i));
	printf("%d\n", ft_printf("|%14c|%015p|\n", 'c', i));
	return (0);
}
