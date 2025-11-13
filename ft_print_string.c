/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:38:21 by achahi            #+#    #+#             */
/*   Updated: 2025/11/13 15:57:24 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putspace(int n, char c)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

static int	ft_putstrn(char *s, int n)
{
	int	i;

	if (!s)
	{
		if (n > 6)
			n = 6;
		return (write(1, "(null)", n));
	}
	i = 0;
	while (i < n && s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (6);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_print_string(char *s, t_format *specs)
{
	int	len;
	int	printed;
	int	pad;

	len = ft_strlen(s);
	if (specs->has_precision && specs->precision < len)
		len = specs->precision;
	pad = specs->width - len;
	printed = 0;
	if (specs->flag_minus)
	{
		printed += ft_putstrn(s, len);
		printed += ft_putspace(pad, ' ');
	}
	else
	{
		printed += ft_putspace(pad, ' ');
		printed += ft_putstrn(s, len);
	}
	return (printed);
}
