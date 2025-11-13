/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:13:00 by achahi            #+#    #+#             */
/*   Updated: 2025/11/12 18:49:48 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_numlen_hex(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	ft_putuhex(unsigned int n)
{
	char	*base;
	int		printed;
	char	c;

	base = "0123456789ABCDEF";
	printed = 0;
	if (n >= 16)
		printed += ft_putuhex(n / 16);
	c = base[n % 16];
	write(1, &c, 1);
	return (printed + 1);
}

static int	ft_putpad(int n, char c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	if (n > 0)
		return (n);
	return (0);
}

static int	ft_put_precision(int n, int len)
{
	int	zeros;

	zeros = n - len;
	if (zeros > 0)
		return (ft_putpad(zeros, '0'));
	return (0);
}

int	ft_print_uhex(unsigned int n, t_format *specs)
{
	int	printed;
	int	len;
	int	pad;

	printed = 0;
	len = ft_numlen_hex(n);
	if (specs->has_precision && specs->precision > len)
		len = specs->precision;
	if (specs->flag_hash && n != 0)
		len += 2;
	pad = specs->width - len;
	if (!specs->flag_minus && (!specs->flag_zero || specs->has_precision))
		printed += ft_putpad(pad, ' ');
	if (specs->flag_hash && n != 0)
		printed += write(1, "0X", 2);
	if (!specs->flag_minus && specs->flag_zero && !specs->has_precision)
		printed += ft_putpad(pad, '0');
	if (specs->has_precision)
		printed += ft_put_precision(specs->precision, ft_numlen_hex(n));
	printed += ft_putuhex(n);
	if (specs->flag_minus)
		printed += ft_putpad(pad, ' ');
	return (printed);
}
