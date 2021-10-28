/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:16:57 by minhkim           #+#    #+#             */
/*   Updated: 2021/10/28 10:38:48 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_putnbr(int n, int fd)
{
	if (n == -2147483648)
	{
		my_putnbr(n / 10, fd);
		my_putchar(8 + '0', fd);
	}
	else if (n < 0)
	{
		my_putchar('-', fd);
		my_putnbr(-n, fd);
	}
	else
	{
		if (n > 9)
			my_putnbr(n / 10, fd);
		my_putchar(n % 10 + '0', fd);
	}
}
