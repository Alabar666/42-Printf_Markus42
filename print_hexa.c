/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:12:50 by marsoare          #+#    #+#             */
/*   Updated: 2024/05/08 01:18:58 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(t_flags *flags, long number, char x)
{
	char	pref;

	pref = ' ';
	if (flags -> zero)
		pref = '0';
	if (flags -> width  && flags -> precision)
		pref = ' ';
	if (flags -> align_left)
		return (print_hexa_left(flags, number, x));
	if (flags -> hash)
		return (print_hexa_hash(flags, number, x, pref));
	if (flags -> width)
		return (print_hexa_width(flags, number, x, pref));
	return (0);
}
