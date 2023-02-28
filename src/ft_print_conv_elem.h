/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_conv_elem.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 17:35:27 by hman          #+#    #+#                 */
/*   Updated: 2021/03/06 13:11:18 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_CONV_ELEM_H
# define FT_PRINT_CONV_ELEM_H

# include <stdarg.h>
# include "ft_conv_element.h"

/*
** this is a struct that pairs a conversion spec character with its
** corresponding function.
*/

typedef struct s_spec_func
{
	char	conv_spec;
	int		(*conv_spec_func)(t_conversion, va_list);
}				t_spec_func;

int	print_conv_elem(t_conversion conv_elem, va_list ap);

#endif