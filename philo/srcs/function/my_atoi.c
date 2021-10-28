/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:13:05 by minhkim           #+#    #+#             */
/*   Updated: 2021/10/28 10:13:07 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	overflowed(int former, int latter)
{
	if (((former >= 0) != ((former << 1) >= 0))
		|| ((former >= 0) != ((former << 2) >= 0))
		|| ((former >= 0) != ((former << 3) >= 0))
		|| ((former >= 0) != (latter >= 0)))
		return (true);
	return (false);
}

bool	jatoi(char **s, int *v)
{
	int	sign;
	int	tmp;

	while (jisspace(**s))
		++(*s);
	sign = 1;
	if (**s == '+' || **s == '-')
		if (*((*s)++) == '-')
			sign = -1;
	if (!jisdigit(**s))
		return (false);
	*v = (*((*s)++) - '0') * sign;
	while (jisdigit(**s))
	{
		tmp = (*((*s)++) - '0');
		if (sign < 0)
			tmp = ~(tmp) + 1;
		tmp = *v * 10 + tmp;
		if (overflowed(*v, tmp))
			return (false);
		*v = tmp;
	}
	if (**s && !jisspace(**s))
		return (false);
	return (true);
}
