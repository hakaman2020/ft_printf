/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 09:42:29 by hman          #+#    #+#                 */
/*   Updated: 2021/03/06 19:43:38 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "../libft/libft.h"
#include "ft_conversion_builder.h"
#include "ft_print_conv_elem.h"
#include "ft_conv_element.h"
#include "ft_printf.h"

/*
**	this function will reset all the variables of the conversion 
**	element to the default value.
*/

static void	reset_conv_elem(t_conversion *conv_elem)
{
	conv_elem->left_align = 0;
	conv_elem->zero_pad = 0;
	conv_elem->min_width = 0;
	conv_elem->precision = -1;
	conv_elem->conversion_spec = 0;
}

/*
** this function will write all the characters of the string until % 
** or end of string
** RETURN the amount of characters written and update the char pointer format
** to the latest position
*/

static int	write_string(const char **format)
{
	char	*tmp_ptr;
	int		difference;

	tmp_ptr = ft_strchr(*format, '%');
	if (tmp_ptr)
		difference = tmp_ptr - *format;
	else
		difference = ft_strlen(*format);
	write(1, *format, difference);
	*format = *format + difference;
	return (difference);
}

/*
** this is the main function ft_printf
** RETURN amount of written characters.
*/

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				count;
	int				temp;
	t_conversion	conv_elem;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		count += write_string(&format);
		if (*format == '%')
		{
			reset_conv_elem(&conv_elem);
			temp = process_conversion(&format, &conv_elem, ap);
			if (temp == -1)
				return (-1);
			else
				count += temp;
			temp = print_conv_elem(conv_elem, ap);
			count += temp;
		}
	}
	va_end(ap);
	return (count);
}
