/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:55:37 by ctirions          #+#    #+#             */
/*   Updated: 2021/01/19 15:24:29 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct		c_list
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
}					j_list;

j_list	p_list;

int			ft_get_element(const char **string);
char		ft_get_first_flag(const char **string);
void		ft_get_first_precision(const char **string);
void		ft_get_second(const char **string);
int			ft_execute(const char **string, char *percent_str);

/*
**		MAIN FONCTIONS
*/

int					ft_printf(const char *string, ...);
void				ft_set_element(void);

/*
**		CONVERT FONCTIONS
*/

int					ft_get_i_d(int n, int size, int neg);
int					ft_get_c(int c);
int					ft_get_x(unsigned int n, const char *hex);
int					ft_get_s(char *string);
int					ft_get_i(int n);
int					ft_get_u(int n);
int					ft_get_p(void *pt);

/*
**		FLAGS FONCTIONS
*/

/*
int					ft_check_flag(const char *string, va_list arg);
int					ft_flag_minus(const char *string, va_list arg);
int					ft_flag_nbr_all(const char *string, va_list arg, int all);
int					ft_flag_zero_point(const char *string, \
					va_list arg, int zeros);
*/

/*
**		ADD FONCTIONS
*/

int					ft_len_arg(const char *string, va_list arg);
int					ft_len_hex_nbr(unsigned long n);
void				ft_put_unsigned_int(unsigned int n);
int					ft_count(unsigned int n);

#endif
