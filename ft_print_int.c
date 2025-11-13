/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:04:54 by achahi            #+#    #+#             */
/*   Updated: 2025/11/13 21:06:03 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_numlen(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_putspace(int n, char c) /*Prints n copies of a character c to standard output.*/
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

static int	put_sign_and_zeros(long num, t_format *specs, int pad)
{
	int	printed;
	int	zero_count;

	printed = 0;
	if (num < 0)
		printed += write(1, "-", 1);
	else if (specs->flag_plus)
		printed += write(1, "+", 1);
	else if (specs->flag_space)
		printed += write(1, " ", 1);
	if (!specs->flag_minus && specs->flag_zero && !specs->has_precision)
		printed += ft_putspace(pad, '0');
	if (specs->has_precision)
	{
		zero_count = specs->precision - (ft_numlen(num) - (num < 0));
		printed += ft_putspace(zero_count, '0');
	}
	return (printed);
}

int	ft_print_int(int n, t_format *specs)
{
	long	num;
	int		len;
	int		printed;
	int		pad;
	int		sign;

	num = n;
	sign = (num < 0 || specs->flag_plus || specs->flag_space);
	if (specs->has_precision && specs->precision == 0 && num == 0)
		len = 0;
	else
		len = ft_numlen(num);
	if (specs->has_precision && specs->precision > len - (num < 0))
		len = (num < 0) + specs->precision;
	pad = specs->width - len - (sign - (num < 0));
	printed = 0;
	if (!specs->flag_minus && (!specs->flag_zero || specs->has_precision))
		printed += ft_putspace(pad, ' ');
	printed += put_sign_and_zeros(num, specs, pad);
	if (!(specs->has_precision && specs->precision == 0 && num == 0))
		printed += ft_putnbr(num);
	if (specs->flag_minus)
		printed += ft_putspace(pad, ' ');
	return (printed);
}
