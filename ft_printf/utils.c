/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:44:17 by minhkim           #+#    #+#             */
/*   Updated: 2021/02/21 10:48:02 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				init_flag(t_info *flag_struct)
{
	flag_struct->minus = 0;
	flag_struct->zero = 0;
	flag_struct->width = 0;
	flag_struct->prec = -1;
	flag_struct->type = 0;
	flag_struct->nbr_base = 10;
	flag_struct->nbr_sign = 1;
}

char				*ft_baseset(char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int					ft_nbrlen(unsigned long long nbr, t_info *flag_struct)
{
	int				i;

	if (nbr == 0 && flag_struct->prec != 0)
		return (1);
	i = 0;
	while (nbr)
	{
		i++;
		nbr /= flag_struct->nbr_base;
	}
	return (i);
}
