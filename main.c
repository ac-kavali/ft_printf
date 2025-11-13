/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:45:16 by achahi            #+#    #+#             */
/*   Updated: 2025/11/13 21:00:48 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#include <stdio.h>



int main(void)
{
    int num = 42;
    int hexNum = 0x1a;

    // Integer with width and precision
    printf("Integer: |%8.5d|\n", num);     // width 8, precision 5
    printf("Left-aligned integer: |%-8.5d|\n", num); // left-aligned

    // Hexadecimal with width and precision
    printf("Hex: |%8.4x|\n", hexNum);      // width 8, precision 4
    printf("Left-aligned hex: |%-8.4x|\n", hexNum);

    // Character
    printf("Character: |%5c|\n", 'A');     // width 5
    printf("Left-aligned char: |%-5c|\n", 'A');

    // Percent sign
    printf("Percent: |    %%|\n");              // width 5 for '%'

    return 0;
}

