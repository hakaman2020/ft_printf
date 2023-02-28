/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hman <hman@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 17:35:33 by hman          #+#    #+#                 */
/*   Updated: 2021/03/04 12:46:52 by hman          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

int		count_digits_decimal(long long number);
int		count_digits_unsigned_number_base(unsigned long long number,
			unsigned int base);
int		print_pad(int amount, char c);
void	print_unsigned_number_base(unsigned long long number,
			unsigned int base, unsigned int caps);
#endif
