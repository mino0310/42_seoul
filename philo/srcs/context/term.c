/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:07:31 by minhkim           #+#    #+#             */
/*   Updated: 2021/10/28 10:07:31 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_arg(t_op *op, t_philo **philo)
{
	int		i;

	i = -1;
	if (op->f)
		while (++i < op->total)
			pthread_mutex_destroy(&op->f[i]);
	jfree((void **)(&op->f));
	jfree((void **)(philo));
	pthread_mutex_destroy(&op->t);
	pthread_mutex_destroy(&op->p);
}

t_exit	exit_invalid(t_op *op, t_philo **philo, void (*f)(void))
{
	if (f)
		f();
	free_arg(op, philo);
	return (INVALID);
}

t_exit	exit_valid(t_op *op, t_philo **philo)
{
	free_arg(op, philo);
	return (VALID);
}
