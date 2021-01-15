/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:31:55 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/15 15:46:15 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("printf\n|%-2c|%i|\n\n", 'L', -12);
	ft_printf("ft_printf\n|%-2c|%i|\n", 'L', -12);
	return (0);
}
