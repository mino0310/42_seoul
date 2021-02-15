/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:02:09 by minhkim           #+#    #+#             */
/*   Updated: 2021/02/13 17:02:46 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*parse_buf(char *str, int end, int len)
{
	int			i;
	char		*buf;

	end = end < len ? end : len;
	if (!(buf = (char *)malloc(sizeof(char) * end + 1)))
		return (NULL);
	i = 0;
	while (i < end)
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int				fill_padding_by_flag(char **buf, t_info *info)
{
	char		*padded_str;
	int			i;

	if (info->width <= (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));
	padded_str = (char *)malloc(sizeof(char) * (info->width - ft_strlen(*buf) + 1));
	i = 0;
	while ((size_t)i < info->width - ft_strlen(*buf))
	{
		padded_str[i] = (info->zero == 1) ? '0' : ' ';
		i++;
	}
	padded_str[i] = '\0';
	if (info->minus == 0)
		*buf = ft_strjoin(padded_str, *buf, 3);
	else
		*buf = ft_strjoin(*buf, padded_str, 3);
	return (info->width);
}

int				print_string(char *str, t_info *info)
{
	int			print_len;
	char		*buf;

	print_len = 0;
	if (str == NULL)
		str = "(null)";
	if (info->prec == -1 || (size_t)info->prec > ft_strlen(str))
		info->prec = ft_strlen(str);
	buf = parse_buf(str, info->prec, ft_strlen(str));
	print_len = fill_padding_by_flag(&buf, info);
	ft_putstr(buf);
	free(buf);
	return (print_len);
}
