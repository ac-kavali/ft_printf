/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:38:18 by achahi            #+#    #+#             */
/*   Updated: 2025/11/10 12:54:36 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	int			printed;
	t_format	specs;

	i = 0;
	printed = 0;
	va_start(args, format);
	ft_process_format(&format, &args, &printed);
	va_end(args);
	return (printed);
}

void	ft_process_format(const char **format, va_list *args, int *printed)
{
	t_format	specs;
	const char	*ptr;

	while (**format)
	{
		if (**format == '%')
		{
			ptr = *format + 1;
			specs = ft_parse_format(&ptr);
			*printed += ft_print_arg(specs, args);
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



int ft_print_arg(t_format specs, va_list *args)
{
    int printed = 0;

    if (specs.specifier == 'c')
        printed += ft_print_char((char)va_arg(*args, int), specs.width, specs.flag_minus);
    else if (specs.specifier == 's')
        printed += ft_print_string(va_arg(*args, char *), specs);
    else if (specs.specifier == 'd' || specs.specifier == 'i')
        printed += ft_print_int(va_arg(*args, int), specs);
    else if (specs.specifier == 'u')
        printed += ft_print_unsigned(va_arg(*args, unsigned int), specs);
    else if (specs.specifier == 'x')
        printed += ft_print_hex(va_arg(*args, unsigned int), specs, 0);
    else if (specs.specifier == 'X')
        printed += ft_print_hex(va_arg(*args, unsigned int), specs, 1);
    else if (specs.specifier == 'p')
        printed += ft_print_pointer(va_arg(*args, void *), specs);
    else if (specs.specifier == '%')
        printed += ft_print_char('%', specs.width, specs.flag_minus);

    return printed;
}
