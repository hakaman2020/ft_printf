/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 17:46:02 by hman          #+#    #+#                 */
/*   Updated: 2021/03/06 14:55:09 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_utils.h"
#include "ft_conv_c.h"

/*
**	this is the conversion fuction for the conversion specification of 'c'
**	it will print the given character
**	RETURN amount of written characters
*/

int	print_character(t_conversion conv_elem, va_list ap)
{
	char	c;
	int		count;

	count = 0;
	c = va_arg(ap, int);
	if (conv_elem.left_align == 1)
	{
		count += write(1, &c, 1);
		if (conv_elem.min_width > 1)
			count += print_pad(conv_elem.min_width - 1, ' ');
	}
	else
	{
		if (conv_elem.min_width > 1)
			count += print_pad(conv_elem.min_width - 1, ' ');
		count += write(1, &c, 1);
	}
	return (count);
}
