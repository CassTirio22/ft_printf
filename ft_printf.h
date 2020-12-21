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

/*
**		MAIN FONCTIONS
*/

int		ft_printf(const char *string, ...);
int		ft_percent(const char **string, va_list arg);

/*
**		CONVERT FONCTIONS
*/

int		ft_convert_i_d(int n);
int		ft_convert_c(int c);
int		ft_convert_x(unsigned int n);
int		ft_convert_majx(unsigned int n);
int		ft_convert_s(char *string);
int		ft_convert_i(int n);
int		ft_convert_u(int n);
int		ft_convert_p(void *pt);

/*
**		FLAGS FONCTIONS
*/
int		ft_check_flag(const char **string, va_list arg);
int		ft_flag_minus(const char **string, va_list arg);
int		ft_flag_nbr_all(const char **string, va_list arg, int all);
int		ft_flag_zero_point(const char **string, va_list arg, int zeros);

/*
**		ADD FONCTIONS
*/

int		ft_len_arg(const char **string, va_list arg);
int		ft_len_hex_nbr(unsigned long n);
void	ft_put_unsigned_int(unsigned int n);
int		ft_count(unsigned int n);

#endif
