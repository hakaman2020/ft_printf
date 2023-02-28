/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_u.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 19:17:24 by hman          #+#    #+#                 */
/*   Updated: 2021/03/06 13:09:05 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_U_H
# define FT_CONV_U_H

# include <stdarg.h>
# include "ft_printf_utils.h"

int			print_unsigned_integer(t_conversion conv_elem, va_list ap);

#endif