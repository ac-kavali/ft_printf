/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:38:18 by achahi            #+#    #+#             */
/*   Updated: 2025/11/13 11:40:43 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_arg(t_format *specs, va_list *args)
{
	int	printed;

	printed = 0;
	if (specs->specifier == 'c')
		printed += ft_print_char((char)va_arg(*args, int), specs);
	else if (specs->specifier == 's')
		printed += ft_print_string(va_arg(*args, char *), specs);
	else if (specs->specifier == 'd' || specs->specifier == 'i')
		printed += ft_print_int(va_arg(*args, int), specs);
	else if (specs->specifier == 'u')
		printed += ft_print_unsigned(va_arg(*args, unsigned int), specs);
	else if (specs->specifier == 'x')
		ft_print_lhex(va_arg(*args, unsigned int), specs, &printed);
	else if (specs->specifier == 'X')
		printed += ft_print_uhex(va_arg(*args, unsigned int), specs);
	else if (specs->specifier == 'p')
		printed += ft_print_ptr(va_arg(*args, void *), specs);
	else if (specs->specifier == '%')
		printed += ft_print_percent(specs);
	return (printed);
}

static void	ft_process_format(const char **format, va_list *args, int *printed)
{
	t_format	specs;
	const char	*ptr;

	while (**format)
	{
		if (**format == '%')
		{
			ptr = *format + 1;
			specs = ft_parse_format(&ptr);
			*printed += ft_print_arg(&specs, args);
			*format = ptr;
		}
		else
		{
			ft_putchar(**format);
			(*printed)++;
			(*format)++;
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;

	printed = 0;
	va_start(args, format);
	ft_process_format(&format, &args, &printed);
	va_end(args);
	return (printed);
}
