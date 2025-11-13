/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_width_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:23:29 by achahi            #+#    #+#             */
/*   Updated: 2025/11/12 18:51:42 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ptr_width_zero(char *s, t_format *specs, int len)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	printed += write(1, "0x", 2);
	while (i++ < (specs->width - len))
		printed += write(1, "0", 1);
	printed += write(1, s + 2, len - 2);
	return (printed);
}
