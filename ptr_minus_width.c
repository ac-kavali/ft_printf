/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_minus_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:21:44 by achahi            #+#    #+#             */
/*   Updated: 2025/11/12 17:23:47 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ptr_minus_width(char *s, t_format *specs, int len)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	printed += write(1, s, len);
	while (i++ < (specs->width - len))
		printed += write(1, " ", 1);
	return (printed);
}
