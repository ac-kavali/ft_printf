/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:04:08 by achahi            #+#    #+#             */
/*   Updated: 2025/11/09 23:48:48 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_format{
	// Flags (0 = not set, 1 = set)
    int flag_hash;      // #
    int flag_zero;      // 0
    int flag_minus;     // -
    int flag_plus;      // +
    int flag_space;     // (space)

    // Width and precision
    int width;          // minimum field width (-1 if not specified)
    int precision;      // precision (-1 if not specified)
    int has_precision;  // 1 if '.' was present, 0 otherwise
    
    char specifier;     // 'd', 's', 'x', 'f', etc.
}t_format;

int	ft_printf(char *format, ...);
int	ft_atoi(const char *nptr);
void	ft_putnbr(int n);

#endi 
