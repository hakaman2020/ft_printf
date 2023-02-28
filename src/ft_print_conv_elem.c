/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_conv_elem.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 16:08:31 by hman          #+#    #+#                 */
/*   Updated: 2021/03/06 14:56:41 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "ft_printf_utils.h"
#include "ft_conv_c.h"
#include "ft_conv_s.h"
#include "ft_conv_p.h"
#include "ft_conv_d_i.h"
#include "ft_conv_u.h"
#include "ft_conv_x_X.h"
#include "ft_conv_percent.h"
#include "ft_print_conv_elem.h"

/*	
**	this function will select the function that belongs to the conversion
**	specification through a dispatch table (jump table)
**	RETURN the amount of characters written
*/	

int	print_conv_elem(t_conversion conv_elem, va_list ap)
{
	static const t_spec_func	spec_func[] = {{'c', &print_character},
		{'s', &print_string}, {'p', &print_pointer_adress},
		{'d', &print_integer}, {'i', &print_integer},
		{'u', &print_unsigned_integer}, {'x', &print_hexidecimal},
		{'X', &print_hexidecimal}, {'\0', NULL}};
	int							i;

	if (conv_elem.conversion_spec == '%')
		return (print_percent());
	i = 0;
	while (spec_func[i].conv_spec != '\0')
	{
		if (spec_func[i].conv_spec == conv_elem.conversion_spec)
			return (spec_func[i].conv_spec_func(conv_elem, ap));
		i++;
	}
	return (0);
}
