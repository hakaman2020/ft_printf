/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_s_linux.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 13:34:52 by hman          #+#    #+#                 */
/*   Updated: 2021/03/06 19:42:12 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "ft_printf_utils.h"
#include "ft_conv_s.h"

/*
**	LINUX version
*/

/*
**	this is the conversion function of the conversion spec 's'
**	here precision is the max amount of characters of string to be written
**	RETURN	amount of written characters
*/

int	print_string(t_conversion conv_elem, va_list ap)
{
	char	*str;
	int		count;

	count = 0;
	str = va_arg(ap, char *);
	if (str == NULL && (conv_elem.precision == -1 || conv_elem.precision > 5))
		str = "(null)";
	else if (str == NULL)
		str = "";
	if (conv_elem.precision == -1 || (conv_elem.precision > (int)
			ft_strlen(str)))
		conv_elem.precision = ft_strlen(str);
	if (conv_elem.left_align == 1)
	{
		count += write(1, str, conv_elem.precision);
		if (conv_elem.min_width > conv_elem.precision)
			count += print_pad(conv_elem.min_width - conv_elem.precision, ' ');
	}
	else
	{
		if (conv_elem.min_width > conv_elem.precision)
			count += print_pad(conv_elem.min_width - conv_elem.precision, ' ');
		count += write(1, str, conv_elem.precision);
	}
	return (count);
}
