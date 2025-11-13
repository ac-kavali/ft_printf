/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:29:41 by achahi            #+#    #+#             */
/*   Updated: 2025/11/13 02:59:35 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_numlen_unsigned(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_putunsigned(unsigned int n)
{
	int		printed;
	char	c;

	printed = 0;
	if (n >= 10)
		printed += ft_putunsigned(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
	return (printed + 1);
}

static int	ft_putspace(int n, char c)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
		ret++;
	}
	if (ret > 0)
		return (ret);
	return (0);
}

int	ft_print_unsigned(unsigned int n, t_format *specs)
{
	int	numlen;
	int	printed;
	int	pad;
	int	zeros;

	printed = 0;
	numlen = ft_numlen_unsigned(n);
	if (specs->has_precision && specs->precision == 0 && n == 0)
	{
		printed += ft_putspace(specs->width, ' ');
		return (printed);
	}
	zeros = 0;
	if (specs->has_precision && specs->precision > numlen)
		zeros = specs->precision - numlen;
	pad = specs->width - (numlen + zeros);
	if (!specs->flag_minus && (!specs->flag_zero || specs->has_precision))
		printed += ft_putspace(pad, ' ');
	if (!specs->flag_minus && specs->flag_zero && !specs->has_precision)
		printed += ft_putspace(pad, '0');
	printed += ft_putspace(zeros, '0');
	printed += ft_putunsigned(n);
	if (specs->flag_minus)
		printed += ft_putspace(pad, ' ');
	return (printed);
}
