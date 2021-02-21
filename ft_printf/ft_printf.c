/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 11:10:52 by minhkim           #+#    #+#             */
/*   Updated: 2021/02/21 11:24:22 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				fill_width_or_prec(va_list ap, char *format,
		t_info *flag_struct, int format_index)
{
	if (ft_isdigit(format[format_index]))
	{
		if (flag_struct->prec == -1)
			flag_struct->width = flag_struct->width * 10
				+ format[format_index] - 48;
		else
			flag_struct->prec = flag_struct->prec * 10
				+ format[format_index] - 48;
	}
	else if (format[format_index] == '*')
	{
		if (flag_struct->prec == -1)
		{
			flag_struct->width = va_arg(ap, int);
			if (flag_struct->width < 0)
			{
				flag_struct->minus = 1;
				flag_struct->width *= -1;
			}
		}
		else
			flag_struct->prec = va_arg(ap, int);
	}
}

void				fill_flag(va_list ap, char *format,
		t_info *flag_struct, int format_index)
{
	if (format[format_index] == '0' && flag_struct->width == 0 &&
			flag_struct->prec == -1)
		flag_struct->zero = 1;
	else if (format[format_index] == '-')
		flag_struct->minus = 1;
	else if (format[format_index] == '.')
		flag_struct->prec = 0;
	else if (ft_isdigit(format[format_index]) || format[format_index] == '*')
		fill_width_or_prec(ap, format, flag_struct, format_index);
}

int					print_by_type(va_list ap, t_info *flag_struct)
{
	int				print_len;
	char			type;

	print_len = 0;
	type = flag_struct->type;
	if (type == 'c')
		print_len = print_char(va_arg(ap, int), flag_struct);
	else if (type == '%')
		print_len = print_char('%', flag_struct);
	else if (type == 's')
		print_len = print_string(va_arg(ap, char *), flag_struct);
	else if (type == 'd' || type == 'i')
		print_len = print_nbr(va_arg(ap, int), flag_struct);
	else if (type == 'x' || type == 'X' || type == 'u')
		print_len = print_nbr(va_arg(ap, unsigned int), flag_struct);
	else if (type == 'p')
		print_len = print_nbr(va_arg(ap, unsigned long long), flag_struct);
	return (print_len);
}

int					parse_format(va_list ap, char *format)
{
	int				i;
	int				print_len;
	t_info			*flag;

	i = 0;
	print_len = 0;
	if (!(flag = malloc(sizeof(t_info))))
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			print_len += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_flag(flag);
			while (format[++i] != '\0' && !(ft_strchr(TYPE, format[i])))
				fill_flag(ap, format, flag, i);
			flag->type = format[i++];
			if ((flag->minus == 1 || flag->prec > -1) && flag->type != '%')
				flag->zero = 0;
			print_len += print_by_type(ap, flag);
		}
	}
	free(flag);
	return (print_len);
}

int					ft_printf(const char *format, ...)
{
	int				print_len;
	va_list			ap;

	va_start(ap, format);
	print_len = parse_format(ap, (char *)format);
	va_end(ap);
	return (print_len);
}
