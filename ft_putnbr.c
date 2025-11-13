/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:32:36 by achahi            #+#    #+#             */
/*   Updated: 2025/11/13 11:31:07 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(long n)
{
	char	c;
	int		printed;

	printed = 0;
	if (n < 0)
		n = -n;
	if (n >= 10)
		printed += ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
	return (printed + 1);
}
