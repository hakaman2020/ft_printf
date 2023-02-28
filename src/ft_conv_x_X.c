/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_x_X.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 19:17:34 by hman          #+#    #+#                 */
/*   Updated: 2021/03/06 14:55:58 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_utils.h"
#include "ft_conv_x_X.h"

/*
**	this function will print the number with left alignment
**	RETURN the amount of written characters
*/

static int	print_hexidecimal_left_align(t_conversion conv_elem,
				unsigned int number, int amount_digits, int base)
{
	int	count;

	count = 0;
	if (conv_elem.precision > amount_digits)
		count += print_pad(conv_elem.precision - amount_digits, '0');
	if (!(number == 0 && conv_elem.precision == 0))
	{	
		if (conv_elem.conversion_spec == 'x')
			print_unsigned_number_base(number, base, 0);
		else if (conv_elem.conversion_spec == 'X')
			print_unsigned_number_base(number, base, 1);
		count += amount_digits;
	}
	if (conv_elem.min_width > count)
		count += print_pad(conv_elem.min_width - count, ' ');
	return (count);
}

/*
**	this function will print the number with left alignment
**	RETURN the amount of written characters
*/

static int	print_hexidecimal_right_align(t_conversion conv_elem,
		unsigned int number, int amount_digits, int base)
{
	int	count;
	int	bigger;

	count = 0;
	bigger = amount_digits;
	if (conv_elem.precision > amount_digits)
		bigger = conv_elem.precision;
	if (conv_elem.min_width > bigger)
	{
		if (conv_elem.zero_pad == 1)
			count += print_pad(conv_elem.min_width - bigger, '0');
		else if (conv_elem.zero_pad == 0)
			count += print_pad(conv_elem.min_width - bigger, ' ');
	}
	if (conv_elem.precision > amount_digits)
		count += print_pad(conv_elem.precision - amount_digits, '0');
	if (!(number == 0 && conv_elem.precision == 0))
	{
		if (conv_elem.conversion_spec == 'x')
			print_unsigned_number_base(number, base, 0);
		else if (conv_elem.conversion_spec == 'X')
			print_unsigned_number_base(number, base, 1);
		count += amount_digits;
	}
	return (count);
}

/*
**	this is the conversion fucntion of the conversion spec 'x' and 'X'
**	RETURN	amount of written characters
*/

int	print_hexidecimal(t_conversion conv_elem, va_list ap)
{
	int				count;
	unsigned int	number;
	int				amount_digits;
	int				base;

	count = 0;
	base = 16;
	if (conv_elem.precision != -1)
		conv_elem.zero_pad = 0;
	number = (unsigned int) va_arg(ap, int);
	amount_digits = count_digits_unsigned_number_base(number, base);
	if (number == 0 && conv_elem.precision == 0)
		amount_digits = 0;
	if (conv_elem.left_align == 1)
		count += print_hexidecimal_left_align(conv_elem, number, amount_digits,
				base);
	else
		count += print_hexidecimal_right_align(conv_elem, number, amount_digits,
				base);
	return (count);
}
