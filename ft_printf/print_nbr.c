/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:50:58 by minhkim           #+#    #+#             */
/*   Updated: 2021/03/11 09:30:32 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					write_nbr_by_prec(unsigned long long nbr,
		t_info *flag_struct, char **buf)
{
	int				nbr_len;
	int				buf_len;
	int				i;

	nbr_len = ft_nbrlen(nbr, flag_struct);
	buf_len = (flag_struct->prec > nbr_len) ?
		flag_struct->prec : nbr_len;
	if (!(*buf = (char *)malloc(sizeof(char) * buf_len + 1)))
		return (0);
	i = 0;
	(*buf)[buf_len] = '\0';
	while (i < buf_len - nbr_len)
		(*buf)[i++] = '0';
	i = 1;
	if (nbr == 0 && flag_struct->prec != 0)
		(*buf)[buf_len - i] = '0';
	while (nbr)
	{
		(*buf)[buf_len - i] = ft_baseset(flag_struct->type)[nbr %
			flag_struct->nbr_base];
		nbr /= flag_struct->nbr_base;
		i++;
	}
	return (nbr_len);
}

int					join_minus(t_info *flag_struct, char **buf)
{
	int				len_to_print;

	len_to_print = 0;
	if ((flag_struct->type == 'i' || flag_struct->type == 'd') &&
			flag_struct->zero == 0 && flag_struct->nbr_sign == -1)
	{
		*buf = ft_strjoin("-", *buf, 2);
		len_to_print = 1;
	}
	return (len_to_print);
}

int					join_hexa_prefix(char **buf)
{
	*buf = ft_strjoin("0x", *buf, 2);
	return (ft_strlen(*buf));
}

int					join_minus2(int buf_len, t_info *flag_struct, char **buf)
{
	int				len_to_print;

	len_to_print = 0;
	if (flag_struct->nbr_sign == -1 && flag_struct->zero == 1)
	{
		if (buf_len >= flag_struct->width)
		{
			*buf = ft_strjoin("-", *buf, 2);
			len_to_print = 1;
		}
		else if (buf_len < flag_struct->width)
			*buf[0] = '-';
	}
	return (len_to_print);
}

int					print_nbr(unsigned long long nbr, t_info *flag_struct)
{
	char			*buf;
	int				buf_len;
	int				print_len;

	if (flag_struct->type == 'x' || flag_struct->type == 'X' ||
			flag_struct->type == 'p')
		flag_struct->nbr_base = 16;
	if ((flag_struct->type == 'd' || flag_struct->type == 'i') &&
			(int)nbr < 0)
	{
		flag_struct->nbr_sign = -1;
		nbr = -nbr;
	}
	buf_len = write_nbr_by_prec(nbr, flag_struct, &buf);
	buf_len += join_minus(flag_struct, &buf);
	if (flag_struct->type == 'p')
		buf_len = join_hexa_prefix(&buf);
	print_len = fill_space_or_zero(&buf, flag_struct);
	print_len += join_minus2(buf_len, flag_struct, &buf);
	ft_putstr(buf);
	free(buf);
	return (print_len);
}
