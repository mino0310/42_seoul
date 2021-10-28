/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:17:36 by minhkim           #+#    #+#             */
/*   Updated: 2021/10/28 10:43:14 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	if (!console(philo, EATING)
		|| !chrono(&philo->cur))
		pthread_mutex_unlock(&philo->op->t);
	++(philo->c);
	elapse(philo, philo->cur, philo->op->time_eat);
	if (philo->op->limit && philo->c == philo->op->limit)
		if (++(philo->op->meet) >= philo->op->total)
			if (!console(philo, FULL))
				pthread_mutex_unlock(&philo->op->t);
}

void	philo_sleep(t_philo *philo)
{
	if (!console(philo, SLEEPING))
		pthread_mutex_unlock(&philo->op->t);
	elapse(philo, 0, philo->op->time_nap);
}

void	philo_think(t_philo *philo)
{
	if (!console(philo, THINKING))
		pthread_mutex_unlock(&philo->op->t);
}
