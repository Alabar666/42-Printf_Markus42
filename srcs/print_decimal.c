/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:30:55 by marsoare          #+#    #+#             */
/*   Updated: 2024/05/09 10:27:02 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(t_flags *flags, long number)
{
	char	sign;
	char	pref;

	sign = '-';
	pref = ' ';
	if (flags -> space)
		sign = ' ';
	if (flags -> plus)
		sign = '+';
	if (flags -> zero)
		pref = '0';
	if (flags -> align_left)
		return (print_decimal_left(number, flags->width,
				flags->precision - 1, sign));
	if (flags -> width > 0 && flags -> precision > 0)
		return (print_dec_wp(number, flags->width, flags->precision - 1, sign));
	if (flags -> width)
		return (print_dec_width(number, flags->width, pref, sign));
	if (flags -> precision)
		return (print_dec_wp(number, flags->width, flags->precision - 1, sign));
	if (number < 0)
		return (ft_putnbr(number));
	if (sign == '+' || sign == ' ')
		return (ft_putchar(sign) + print_unsigned_dec(number));
	return (print_unsigned_dec(number));
}
