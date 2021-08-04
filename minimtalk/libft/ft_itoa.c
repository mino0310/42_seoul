/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:48:45 by minhkim           #+#    #+#             */
/*   Updated: 2020/10/15 13:18:45 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int			ft_abs(long int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

int					ft_len(long int nbr)
{
	int				len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	int				len;
	int				sign;
	char			*c;

	sign = (n < 0) ? -1 : 1;
	len = ft_len(n);
	if ((c = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
