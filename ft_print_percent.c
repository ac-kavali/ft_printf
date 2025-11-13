/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:01:56 by achahi            #+#    #+#             */
/*   Updated: 2025/11/12 11:02:51 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putspace(int n, char c)
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

int	ft_print_percent(t_format *specs)
{
	int	printed;
	int	pad;

	printed = 0;
	pad = specs->width - 1;
	if (!specs->flag_minus && !specs->flag_zero)
		printed += ft_putspace(pad, ' ');
	if (!specs->flag_minus && specs->flag_zero)
		printed += ft_putspace(pad, '0');
	printed += write(1, "%", 1);
	if (specs->flag_minus)
		printed += ft_putspace(pad, ' ');
	return (printed);
}
