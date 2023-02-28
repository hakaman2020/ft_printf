/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_element.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 17:34:59 by hman          #+#    #+#                 */
/*   Updated: 2021/03/06 14:51:49 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_ELEMENT_H
# define FT_CONV_ELEMENT_H

/*
**	struct to contain the conversion elements
*/

typedef struct s_conversion
{
	int		left_align;
	int		zero_pad;
	int		min_width;
	int		precision;
	char	conversion_spec;
}				t_conversion;

#endif