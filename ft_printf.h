/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:44:55 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/10 13:05:50 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct		c_list
{
	char	*final_string;
	char	*value;
	va_list	arg;
	char	percent;
	char	flag;
	int		point;
	int		precision1;
	int		precision2;
	int		res;
	int		error;
}					j_list;

j_list	p_list;

int		ft_get_element(const char **string);
char	ft_get_first_flag(const char **string);
void	ft_get_first_precision(const char **string);
void	ft_get_second(const char **string);

/*
**		MAIN FONCTIONS
*/

int					ft_printf(const char *string, ...);
void				ft_set_element(void);

/*
**		CONVERT FONCTIONS
*/

int					ft_convert_i_d(int n);
int					ft_convert_c(int c);
int					ft_convert_x(unsigned int n);
int					ft_convert_majx(unsigned int n);
int					ft_convert_s(char *string);
int					ft_convert_i(int n);
int					ft_convert_u(int n);
int					ft_convert_p(void *pt);

/*
**		FLAGS FONCTIONS
*/

int					ft_check_flag(const char *string, va_list arg);
int					ft_flag_minus(const char *string, va_list arg);
int					ft_flag_nbr_all(const char *string, va_list arg, int all);
int					ft_flag_zero_point(const char *string, \
					va_list arg, int zeros);

/*
**		ADD FONCTIONS
*/

int					ft_len_arg(const char *string, va_list arg);
int					ft_len_hex_nbr(unsigned long n);
void				ft_put_unsigned_int(unsigned int n);
int					ft_count(unsigned int n);

#endif
