/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:17:18 by minhkim           #+#    #+#             */
/*   Updated: 2021/10/28 10:17:18 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	text(t_cond cond)
{
	if (cond == DEAD)
		jputendl("\033[0;31m died\033[0;0m", STDOUT_FILENO);
	else if (cond == GRAB)
		jputendl("\033[1;33m has taken a fork\033[0;0m", STDOUT_FILENO);
	else if (cond == EATING)
		jputendl("\033[0;32m is eating\033[0;0m", STDOUT_FILENO);
	else if (cond == SLEEPING)
		jputendl("\033[0;35m is sleeping\033[0;0m", STDOUT_FILENO);
	else if (cond == THINKING)
		jputendl("\033[0;36m is thinking\033[0;0m", STDOUT_FILENO);
}

bool	console(t_philo *philo, t_cond cond)
{
	long long	cur;

	if (pthread_mutex_lock(&philo->op->p)
		|| !chrono(&cur))
		return (false);
	jputstr("\033[30;47;20m", STDOUT_FILENO);
	jputnbr(cur - philo->op->begin, STDOUT_FILENO);
	if (cond == FULL)
		jputendl("\033[30;47;20m\tFinished!", STDOUT_FILENO);
	else
	{
		jputstr("\033[0;0m\033[1;37m\t", STDOUT_FILENO);
		jputnbr(philo->i + 1, STDOUT_FILENO);
		text(cond);
	}
	if (cond == DEAD || cond == FULL)
		return (false);
	if (pthread_mutex_unlock(&philo->op->p))
		return (false);
	return (true);
}
