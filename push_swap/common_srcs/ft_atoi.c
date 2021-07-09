/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:40:30 by minhkim           #+#    #+#             */
/*   Updated: 2021/07/09 13:42:41 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	n;
	int			sign;

	while (*str == '\n' || *str == '\t' || *str == ' '
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	sign = 1;
	if (*str == '+')
	{
		sign = 1;
		str++;
	}
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = 10 * n + *str - '0';
		str++;
	}
	return (sign * n);
}
