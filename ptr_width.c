/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:22:33 by achahi            #+#    #+#             */
/*   Updated: 2025/11/12 09:31:52 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ptr_width(char *s, t_format *specs, int len)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	while (i++ < (specs->width - len))
		printed += write(1, " ", 1);
	printed += write(1, s, len);
	return (printed);
}
