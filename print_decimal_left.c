/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:58:30 by marsoare          #+#    #+#             */
/*   Updated: 2024/05/04 21:28:37 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal_left(long number, int width, int prec, char sign)
{
	int	count;

	count = 0;
	if (number == 0 && width > 0)
	{
		if (sign == '+' || sign == ' ')
			count += ft_putchar(sign);
		if (prec != 0)
			count += ft_putchar('0');
		while (count < prec)
			count += ft_putchar('0');
		if (!prec)
			count += ft_putchar('0');
		while (count < width)
			count += ft_putchar(' ');
		return (count);
	}
	count += print_decimal_prec(number, prec, sign);
	while (count < width)
		count += ft_putchar(' ');
	return (count);
}
