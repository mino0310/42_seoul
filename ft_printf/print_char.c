/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:48:07 by minhkim           #+#    #+#             */
/*   Updated: 2021/02/21 10:49:23 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					print_space_or_zero(int width, int str_len, int zero_flag)
{
	int				print_len;

	print_len = 0;
	while (str_len < width)
	{
		if (zero_flag == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		print_len++;
		str_len++;
	}
	return (print_len);
}

int					print_char(int c, t_info *flag_struct)
{
	int				print_len;

	print_len = 0;
	if (flag_struct->type == '%' && flag_struct->minus == 1)
		flag_struct->zero = 0;
	if (flag_struct->minus == 1)
		print_len += ft_putchar(c);
	print_len += print_space_or_zero(flag_struct->width, 1, flag_struct->zero);
	if (flag_struct->minus == 0)
		print_len += ft_putchar(c);
	return (print_len);
}
