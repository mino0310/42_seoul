/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:49:48 by minhkim           #+#    #+#             */
/*   Updated: 2021/02/21 18:10:17 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*parse_buf(char *str, int prec, int str_len)
{
	int				index;
	char			*buf;

	prec = prec < str_len ? prec : str_len;
	if (!(buf = (char *)malloc(sizeof(char) * prec + 1)))
		return (NULL);
	index = 0;
	while (index < prec)
	{
		buf[index] = str[index];
		index++;
	}
	buf[index] = '\0';
	return (buf);
}

int					fill_space_or_zero(char **buf, t_info *flag_struct)
{
	char			*flag_buf;
	int				i;

	if (flag_struct->width <= (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));
	flag_buf = (char *)malloc(sizeof(char) *
			(flag_struct->width - ft_strlen(*buf) + 1));
	i = 0;
	while ((size_t)i < flag_struct->width - ft_strlen(*buf))
	{
		flag_buf[i] = (flag_struct->zero == 1) ? '0' : ' ';
		i++;
	}
	flag_buf[i] = '\0';
	if (flag_struct->minus == 0)
		*buf = ft_strjoin(flag_buf, *buf, 3);
	else
		*buf = ft_strjoin(*buf, flag_buf, 3);
	return (flag_struct->width);
}

int					print_string(char *str, t_info *flag_struct)
{
	int				print_len;
	char			*print_buf;

	print_len = 0;
	if (str == NULL)
		str = "(null)";
	if (flag_struct->prec == -1 ||
			(size_t)flag_struct->prec > ft_strlen(str))
		flag_struct->prec = ft_strlen(str);
	print_buf = parse_buf(str, flag_struct->prec, ft_strlen(str));
	print_len = fill_space_or_zero(&print_buf, flag_struct);
	ft_putstr(print_buf);
	free(print_buf);
	return (print_len);
}
