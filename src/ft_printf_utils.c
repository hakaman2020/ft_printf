/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 13:41:33 by hman          #+#    #+#                 */
/*   Updated: 2021/03/06 15:02:54 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_utils.h"

/*
**	this function counts the amount of digits in a decimal integer number
**	if the number is negative it will only count the digits.
**	RETURN amount of digits in a number
*/

int	count_digits_decimal(long long number)
{
	int	count;

	count = 1;
	if (number < 0)
		number = number * -1;
	while (number > 9)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

/*
**	this function will determine the amount of digits the input number will
**	have after conversion with a certain base.
**	octal for base =8, decimal for base 10, hexidecimal for base 16
**	RETURN the amount of digits in the converted number 
*/

int	count_digits_unsigned_number_base(unsigned long long number,
	unsigned int base)
{
	int	count;

	count = 1;
	while (number > (base - 1))
	{
		number = number / base;
		count++;
	}
	return (count);
}

/*
**	this function will print the padding with the given character
**	RETURN amount of characters written
*/

int	print_pad(int amount, char c)
{
	int	count;

	count = 0;
	while (count < amount)
	{
		write(1, &c, 1);
		count++;
	}
	return (amount);
}

/*
**	this function will print a number in the base format
**  octal for base =8, decimal for base 10, hexidecimal for base 16
**	base = 0 is uncapitalized characters 
**	base = 1 is for capitalized characters
*/

void	print_unsigned_number_base(unsigned long long number, unsigned int base,
		unsigned int caps)
{
	static const char	*digits = "0123456789abcdef";
	static const char	*digits_caps = "0123456789ABCDEF";

	if (number > (base - 1))
		print_unsigned_number_base(number / base, base, caps);
	number = number % base;
	if (caps == 0)
		write(1, &digits[number], 1);
	else
		write(1, &digits_caps[number], 1);
}
