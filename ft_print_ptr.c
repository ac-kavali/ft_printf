/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:21:43 by achahi            #+#    #+#             */
/*   Updated: 2025/11/13 15:57:48 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_ptr(void *ptr, t_format *specs);
void	ft_put_hex(unsigned long num, char *buff);
int		hex_len(unsigned long num);
int		ft_print_str(char *s, t_format *specs);
int		ft_print_nil(t_format *specs);

int	ft_print_ptr(void *ptr, t_format *specs)
{
	unsigned long	num;
	char			buff[19];

	if (ptr == NULL)
		return (ft_print_nil(specs));
	num = (unsigned long)ptr;
	ft_put_hex(num, buff);
	return (ft_print_str(buff, specs));
}

int	ft_print_nil(t_format *specs)
{
	int	printed;
	int	pad;

	printed = 0;
	pad = specs->width - 5;
	if (specs->flag_minus)
	{
		printed += write(1, "(nil)", 5);
		while (pad-- > 0)
			printed += write(1, " ", 1);
	}
	else
	{
		while (pad-- > 0)
			printed += write(1, " ", 1);
		printed += write(1, "(nil)", 5);
	}
	return (printed);
}

void	ft_put_hex(unsigned long num, char *buff)
{
	char	*base;
	int		len;

	if (num == 0)
	{
		buff[0] = '0';
		buff[1] = 'x';
		buff[2] = '0';
		buff[3] = '\0';
		return ;
	}
	base = "0123456789abcdef";
	len = hex_len(num);
	buff[len + 2] = '\0';
	while (len-- > 0)
	{
		buff[len + 2] = base[num % 16];
		num /= 16;
	}
	buff[0] = '0';
	buff[1] = 'x';
}

int	hex_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	ft_print_str(char *s, t_format *specs)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (len < specs->width)
	{
		if (specs->flag_minus)
			return (ptr_minus_width(s, specs, len));
		else if (specs->flag_zero)
			return (ptr_width_zero(s, specs, len));
		else
			return (ptr_width(s, specs, len));
	}
	return (write(1, s, len));
}
