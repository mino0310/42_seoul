/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 09:40:18 by minhkim           #+#    #+#             */
/*   Updated: 2021/02/07 10:23:02 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_type(va_list ap, t_info *info)
{
	int			ret;
	char		type;

	ret = 0;
	type = info->type;
	if (type == 'c')
		ret = print_char(va_arg(ap, int), info);
	else if (type == '%')
		ret = print_char('%', info);
	else if (type == 's')
		ret = print_string(va_arg(ap, char *), info);
	else if (type == 'd' || type == 'i')
		ret = print_nbr(va_arg(ag, int), info);
	else if (type == 'x' || type == 'X' || type == 'u')
		ret = print_nbr(va_arg(ag, unsigned int), info);
	else if (type == 'p')
		ret = print_nbr(va_arg(ap, unsigned long long), info);
	return (ret);
}

void			check_width_and_prec(va_list ap,
		char *format, t_info *info, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + format[i] - 48;
		else
			info->prec = info->prec * 10 + format[i] - 48;
	}
	else if (format[i] == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->prec = va_arg(ap, int);
	}
}

void			check_info(va_list ap, char *format, t_info *info, int i)
{
	if (format[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '.')
		info->prec = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		check_width_and_prec(ap, format, info, i);
}

int				parse_format(va_list ap, char *format)
{
	int				i;
	int				ret;
	t_info			*info;

	i = 0;
	ret = 0;
	if (!(info = malloc(sizeof(t_info) * 1)))
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			ret += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_info(info);
			while (format[++i] != '\0' && !(ft_strchr(TYPE, format[i])))
				check_info(ap, info, i);
			info->type = format[i++];
			if ((info->minus == 1 || info->prec > -1) && info->type != '%')
				info->zero = 0;
			ret += print_type(ap, info);
		}
	}
	free(info);
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	int				ret;
	va_list			ap;

	va_start(ap, format);
	ret = parse_format(ap, (char *)format);
	va_end(ap);
	return (ret);
}
