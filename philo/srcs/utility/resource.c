/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:17:23 by minhkim           #+#    #+#             */
/*   Updated: 2021/10/28 10:43:10 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->op->f[philo->l])
		|| !console(philo, GRAB)
		|| pthread_mutex_lock(&philo->op->f[philo->r])
		|| !console(philo, GRAB))
		pthread_mutex_unlock(&philo->op->t);
}

void	put_fork(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->op->f[philo->l])
		|| pthread_mutex_unlock(&philo->op->f[philo->r]))
		pthread_mutex_unlock(&philo->op->t);
}
