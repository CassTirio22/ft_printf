/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:19:04 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/24 13:26:28 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef		structc_list
{
	char	*str;
	char	*value;
	char	percent;
	char	flag;
	int		point;
	int		prec1;
	int		prec2;
	int		res;
	int		error;
	va_list	arg;
}			j_list;

j_list	p_list;

/*
**		MAIN FONCTIONS
*/

int			ft_printf(const char *string, ...);
void		ft_set_element(void);
int			ft_execute(const char **string, char *percent_str, int i, char *hex);


/*
**		GETS FONCTIONS
*/

int			ft_get_element(const char **string);
char		ft_get_first_flag(const char **string);
void		ft_get_first_precision(const char **string);
void		ft_get_second(const char **string);

/*
**		CONVERT FONCTIONS
*/

int			ft_get_i_d(int n, int size, int neg);
int			ft_get_c(int c);
int			ft_get_x(unsigned int n, const char *hex);
int			ft_get_s(char *string);
int			ft_get_i(int n);
int			ft_get_u(int n);
int			ft_get_p(void *pt,char *hex, int i);

/*
**		ADDS FONCTIONS
*/

int			ft_len_arg(const char *string, va_list arg);
int			ft_len_hex_nbr(unsigned long n);
void		ft_put_unsigned_int(unsigned int n);
int			ft_count(unsigned int n);

#endif
