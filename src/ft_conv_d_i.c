/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_d_i.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 13:25:15 by hman          #+#    #+#                 */
/*   Updated: 2021/03/06 18:26:22 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_utils.h"
#include "ft_conv_d_i.h"

/*
**	this function will print a positive number 
*/

static void	print_number(long long number)
{
	char	digit;

	if (number < 0)
		number *= -1;
	if (number > 9)
		print_number(number / 10);
	digit = (number % 10) + '0';
	write(1, &digit, 1);
}

/*
**	this function will print the number with left alignment
**	RETURN the amount of written characters
*/

static int	print_int_left_align(t_conversion conv_elem, long long number,
		int amount_digits, int neg_sign)
{
	int	count;

	count = 0;
	if (neg_sign == 1)
		count += write(1, "-", 1);
	if (conv_elem.precision > amount_digits)
		count += print_pad(conv_elem.precision - amount_digits, '0');
	if (!(number == 0 && conv_elem.precision == 0))
	{
		print_number(number);
		count += amount_digits;
	}
	if (conv_elem.min_width > count)
		count += print_pad(conv_elem.min_width - count, ' ');
	return (count);
}

/*
**	this function will print the padding in right align
**	RETURN the amount of written characters
*/

static int	padding_right_align(t_conversion conv_elem, int neg_sign,
		int bigger, int count)
{
	if (conv_elem.zero_pad == 1)
	{	
		if (neg_sign == 1)
			count += write(1, "-", 1);
		count += print_pad(conv_elem.min_width - (neg_sign + bigger), '0');
	}
	else if (conv_elem.zero_pad == 0)
	{
		count += print_pad(conv_elem.min_width - (neg_sign + bigger), ' ');
		if (neg_sign == 1)
			count += write(1, "-", 1);
	}
	return (count);
}

/*
**	this function will print the number with left alignment
**	RETURN the amount of written characters
*/

static int	print_int_right_align(t_conversion conv_elem, long long number,
		int amount_digits, int neg_sign)
{
	int	count;
	int	bigger;

	count = 0;
	bigger = amount_digits;
	if (conv_elem.precision > amount_digits)
		bigger = conv_elem.precision;
	if (conv_elem.min_width > (neg_sign + bigger))
	{
		count += padding_right_align(conv_elem, neg_sign, bigger, count);
	}
	else
	{
		if (neg_sign == 1)
			count += write(1, "-", 1);
	}
	if (conv_elem.precision > amount_digits)
		count += print_pad(conv_elem.precision - amount_digits, '0');
	if (!(number == 0 && conv_elem.precision == 0))
	{
		print_number(number);
		count += amount_digits;
	}
	return (count);
}

/*
**	this is the conversion function of the conversion spec 'd' and 'i'
**	RETURN	amount of written characters
*/

int	print_integer(t_conversion conv_elem, va_list ap)
{
	int			count;
	long long	number;
	int			amount_digits;
	int			neg_sign;

	count = 0;
	neg_sign = 0;
	if (conv_elem.precision != -1)
		conv_elem.zero_pad = 0;
	number = va_arg(ap, int);
	if (number < 0)
	{
		neg_sign = 1;
		number *= -1;
	}
	amount_digits = count_digits_decimal(number);
	if (number == 0 && conv_elem.precision == 0)
		amount_digits = 0;
	if (conv_elem.left_align == 1)
		count += print_int_left_align(conv_elem, number, amount_digits,
				neg_sign);
	else
		count += print_int_right_align(conv_elem, number, amount_digits,
				neg_sign);
	return (count);
}
