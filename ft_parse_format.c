/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:11:40 by achahi            #+#    #+#             */
/*   Updated: 2025/11/12 17:26:00 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_set_flags(const char **format, t_format *specs)
{
	while (**format && ft_isflag(**format))
	{
		if (**format == '-')
			specs->flag_minus = 1;
		if (**format == '+')
			specs->flag_plus = 1;
		if (**format == ' ')
			specs->flag_space = 1;
		if (**format == '#')
			specs->flag_hash = 1;
		if (**format == '0')
			specs->flag_zero = 1;
		(*format)++;
	}
}

static void	ft_set_width(const char **format, t_format *specs)
{
	int	num;

	num = 0;
	while (**format && **format >= '0' && **format <= '9')
	{
		num = num * 10 + (**format - '0');
		(*format)++;
	}
	specs->width = num;
}

static void	ft_set_precision(const char **format, t_format *specs)
{
	int	num;

	num = 0;
	if (**format == '.')
	{
		specs->has_precision = 1;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			num = num * 10 + (**format - '0');
			(*format)++;
		}
		specs->precision = num;
	}
}

static void	ft_set_specifier(const char **format, t_format *specs)
{
	char	c;

	c = **format;
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
	{
		specs->specifier = c;
		(*format)++;
	}
	else
	{
		specs->specifier = 0;
	}
}

t_format	ft_parse_format(const char **format)
{
	t_format	specs;

	specs = (t_format){0};
	specs.precision = -1;
	ft_set_flags(format, &specs);
	ft_set_width(format, &specs);
	ft_set_precision(format, &specs);
	ft_set_specifier(format, &specs);
	return (specs);
}
