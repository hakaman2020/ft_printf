/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_percent.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 13:45:04 by hman          #+#    #+#                 */
/*   Updated: 2021/03/06 14:52:13 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_conv_percent.h"

/*
** this is the conversion function of the conversion spec '%'
**	RETURN	amount of written characters
*/

int	print_percent(void)
{
	return (write(1, "%", 1));
}
