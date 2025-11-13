/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:04:08 by achahi            #+#    #+#             */
/*   Updated: 2025/11/13 17:20:39 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

typedef struct s_format
{
	int		flag_hash;
	int		flag_zero;
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		width;
	int		precision;
	int		has_precision;
	char	specifier;
}t_format;

t_format	ft_parse_format(const char **format);
int			ft_printf(const char *format, ...);
int			ft_print_ptr(void *ptr, t_format *specs);
int			ft_print_char(char c, t_format *specs);
int			ft_print_string(char *s, t_format *specs);
int			ptr_width(char *s, t_format *specs, int len);
int			ptr_minus_width(char *s, t_format *specs, int len);
int			ptr_width_zero(char *s, t_format *specs, int len);
int			ft_print_int(int n, t_format *specs);
int			ft_isflag(char c);
int			ft_print_lhex(unsigned int n, t_format *specs, int *printed);
int			ft_print_uhex(unsigned int n, t_format *specs);
int			ft_print_percent(t_format *specs);
int			ft_print_unsigned(unsigned int n, t_format *specs);
int			ft_putchar(char c);
int			ft_putnbr(long n);

#endif
