/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_p.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 08:10:59 by hman          #+#    #+#                 */
/*   Updated: 2021/03/07 08:11:21 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_utils.h"
#include "ft_conv_p.h"

/*
**	MACOS version
*/

/*
**	this function will print the pointer address with left alignment
**	RETURN the amount of written characters
*/

static int	print_pointer_left_align(t_conversion conv_elem,
				unsigned long long number, int amount_digits, int base)
{
	int	count;

	count = 0;
	if (number == 0)
		count += write(1, "0x0", 3);
	else
	{
		count += write(1, "0x", 2);
		print_unsigned_number_base(number, base, 0);
		count += amount_digits;
	}
	if (conv_elem.min_width > count)
		count += print_pad(conv_elem.min_width - count, ' ');
	return (count);
}

/*
**	this function will print the pionter address with left alignment
**	RETURN the amount of written characters
*/

static int	print_pointer_right_align(t_conversion conv_elem,
		unsigned long long number, int amount_digits, int base)
{
	int	count;

	count = 0;
	if (number == 0)
	{
		if (conv_elem.min_width > 3)
			count += print_pad(conv_elem.min_width - 3, ' ');
		count += write(1, "0x0", 3);
	}
	else
	{
		if (conv_elem.min_width > (amount_digits + 2))
			count += print_pad(conv_elem.min_width - (amount_digits + 2), ' ');
		count += write(1, "0x", 2);
		print_unsigned_number_base(number, base, 0);
		count += amount_digits;
	}
	return (count);
}

/*
**	this is the conversion function of the conversion spec 'p'
**	RETURN	amount of written characters
*/

int	print_pointer_adress(t_conversion conv_elem, va_list ap)
{
	int					count;
	unsigned long long	number;
	int					amount_digits;
	int					base;

	count = 0;
	base = 16;
	number = (unsigned long long) va_arg(ap, void *);
	amount_digits = count_digits_unsigned_number_base(number, base);
	if (conv_elem.left_align == 1)
		count += print_pointer_left_align(conv_elem, number, amount_digits,
				base);
	else
		count += print_pointer_right_align(conv_elem, number, amount_digits,
				base);
	return (count);
}
