/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conversion_builder.h                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 17:35:20 by hman          #+#    #+#                 */
/*   Updated: 2021/03/06 15:01:16 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSION_BUILDER_H
# define FT_CONVERSION_BUILDER_H

# include <stdarg.h>
# include "ft_conv_element.h"

int	process_conversion(const char **format, t_conversion *conv_elem,
		va_list ap);

#endif