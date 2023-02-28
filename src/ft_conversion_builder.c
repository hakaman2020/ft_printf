/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conversion_builder.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 09:43:03 by hman          #+#    #+#                 */
/*   Updated: 2021/05/04 10:58:29 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "ft_conversion_builder.h"

/*
**	this function process the flags 
**	'-' for left alignment
** 	'0' for zero padding on the leftside
*/

static void	process_flags(const char **str_ptr, t_conversion *conv_elem)
{
	while (**str_ptr == '-' || **str_ptr == '0')
	{
		if (**str_ptr == '-')
			conv_elem->left_align = 1;
		else if (**str_ptr == '0')
			conv_elem->zero_pad = 1;
		(*str_ptr)++;
	}
}

/*
**	this function determine the minimal width
*/

static void	process_min_width(const char **str_ptr, t_conversion *conv_elem,
	va_list ap)
{
	int	min_width;

	min_width = 0;
	if (**str_ptr == '*')
	{
		min_width = va_arg(ap, int);
		if (min_width < 0)
		{
			conv_elem->left_align = 1;
			min_width *= -1;
		}
		conv_elem->min_width = min_width;
		(*str_ptr)++;
	}
	else
	{
		while (ft_isdigit(**str_ptr))
		{
			min_width = (min_width * 10) + (**str_ptr - 48);
			(*str_ptr)++;
		}
		conv_elem->min_width = min_width;
	}
}

/*
**	this function determine the precision
*/

static void	process_precision(const char **str_ptr, t_conversion *conv_elem,
	va_list ap)
{
	int	precision;

	precision = 0;
	if (**str_ptr == '.')
	{
		(*str_ptr)++;
		if (**str_ptr == '*')
		{
			precision = va_arg(ap, int);
			if (precision >= 0)
				conv_elem->precision = precision;
			(*str_ptr)++;
		}
		else if (ft_isdigit(**str_ptr))
		{
			while (ft_isdigit(**str_ptr))
			{
				precision = (precision * 10) + (**str_ptr - 48);
				(*str_ptr)++;
			}
			conv_elem->precision = precision;
		}
		else
			conv_elem->precision = 0;
	}
}

/*
** this function will determine the conversion specification. If one is found
** it will return 1 else it will return 0
** RETURN 	1 if conversion specification is found
**			0 if conversion specification is not found
*/

static int	process_conv_spec(const char **str_ptr, t_conversion *conv_elem)
{
	char	*temp;

	temp = ft_strchr("cspdiuxX%", **str_ptr);
	if (temp != NULL && *temp != '\0')
	{
		conv_elem->conversion_spec = **str_ptr;
		(*str_ptr)++;
		return (1);
	}
	else
		return (0);
}

/*
** this function start will process the conversion spec
** and will write it to stdout
** RETURN the amount of characters written
*/

int	process_conversion(const char **format, t_conversion *conv_elem, va_list ap)
{
	const char	*str_ptr;

	str_ptr = *format;
	str_ptr++;
	if (*str_ptr == '\0')
		return (-1);
	process_flags(&str_ptr, conv_elem);
	process_min_width(&str_ptr, conv_elem, ap);
	process_precision(&str_ptr, conv_elem, ap);
	if (process_conv_spec(&str_ptr, conv_elem))
	{
		*format = str_ptr;
		return (0);
	}
	else
	{
		write(1, *format, 1);
		(*format)++;
		return (1);
	}
}
