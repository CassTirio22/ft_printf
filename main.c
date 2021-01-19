/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:31:55 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/19 18:32:35 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{	
	int i = -27;

	printf("%d\n", printf("|%014.4s|%016.12d|\n", NULL, INT_MIN));
	printf("%d\n", ft_printf("|%014.4s|%016.12d|\n", NULL, INT_MIN));
	return (0);
}
