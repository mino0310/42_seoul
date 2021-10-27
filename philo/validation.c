/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 03:31:40 by minhkim           #+#    #+#             */
/*   Updated: 2021/10/28 03:31:41 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_positive_number(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s < 48 || *s > 57)
			return (0);
		s++;
	}
	return (1);
}

bool	validation(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (0);
	}
	while (argv[i])
	{
		if (!is_positive_number(argv[i]))
		{
			write(2, "Wrong argument\n", 15);
			return (0);
		}
		i++;
	}
	return (1);
}
