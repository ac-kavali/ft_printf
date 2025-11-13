/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:12:04 by achahi            #+#    #+#             */
/*   Updated: 2025/11/12 19:38:13 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	numlen_hex(unsigned int n)
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

static int	putlhex(unsigned int n)
{
	char	*base;
	int		printed;
	char	c;

	base = "0123456789abcdef";
	printed = 0;
	if (n >= 16)
		printed += putlhex(n / 16);
	c = base[n % 16];
	write(1, &c, 1);
	return (printed + 1);
}

static void	prep(t_format *specs, unsigned int n, int pad, int *printed)
{
	if (!specs->flag_minus && (!specs->flag_zero || specs->has_precision))
		while (pad-- > 0)
			*printed += write(1, " ", 1);
	if (specs->flag_hash && n != 0)
		*printed += write(1, "0x", 2);
	if (!specs->flag_minus && specs->flag_zero && !specs->has_precision)
		while (pad-- > 0)
			*printed += write(1, "0", 1);
	if (specs->has_precision)
		while (specs->precision-- - numlen_hex(n) > 0)
			*printed += write(1, "0", 1);
}

static void	numr(t_format *specs, unsigned int n, int pad, int *printed)
{
	*printed += putlhex(n);
	if (specs->flag_minus)
		while (pad-- > 0)
			*printed += write(1, " ", 1);
}

int	ft_print_lhex(unsigned int n, t_format *specs, int *printed)
{
	int	len;
	int	pad;

	len = numlen_hex(n);
	if (specs->has_precision && specs->precision > len)
		len = specs->precision;
	if (specs->flag_hash && n != 0)
		len += 2;
	pad = specs->width - len;
	prep(specs, n, pad, printed);
	numr(specs, n, pad, printed);
	return (*printed);
}
