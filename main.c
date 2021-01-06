/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:32:47 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/22 14:55:30 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char *str = "---------13.12";
	printf("str : %s\n", str);
	//printf("YO%0*.3dyo\n", 12, 12);
	ft_get_element((const char **)&str);
	return (0);
}
