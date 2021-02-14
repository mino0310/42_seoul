/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:32:28 by minhkim           #+#    #+#             */
/*   Updated: 2021/02/09 12:36:15 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				write_width_by_flag(int width, int len, int zero_flag)
{
	int			print_flag_len;

	print_flag_len = 0;
	while (len < width)
	{
		if (zero_flag == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		print_flag_len++;
	}
	return (print_flag_len);
}

int				print_char(int c, t_info *info)
{
	int			print_len;

	print_len = 0;
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus == 1)
		print_len += ft_putchar(c);
	print_len += write_width_by_flag(info->width, 1, info->zero);
	if (info->minus == 0)
		print_len += ft_putchar(c);
	return (print_len);
}
