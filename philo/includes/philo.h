/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhkim <minhkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:07:21 by minhkim           #+#    #+#             */
/*   Updated: 2021/10/28 10:40:49 by minhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/*
** =============================================================================
** Macro Declaration
** =============================================================================
*/

# define EPSILON		10
# define MILLI			1000

/*
** =============================================================================
** Type Definitions
** =============================================================================
*/

typedef pthread_t		t_th;
typedef pthread_mutex_t	t_mu;

/*
** =============================================================================
** Enum Type Definitions
** =============================================================================
*/

typedef enum e_exit
{
	VALID,
	INVALID,
}					t_exit;

typedef enum e_stat
{
	ERROR = -1,
	SUCCESS,
}					t_stat;

typedef enum e_cond
{
	DEAD,
	GRAB,
	EATING,
	SLEEPING,
	THINKING,
	FULL,
}					t_cond;

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_op
{
	int				total;
	int				time_die;
	int				time_eat;
	int				time_nap;
	int				limit;
	int				meet;
	t_mu			p;
	t_mu			t;
	t_mu			*f;
	long long		begin;
}					t_op;

typedef struct s_philo
{
	int				i;
	int				l;
	int				r;
	int				c;
	t_th			th;
	t_th			mo;
	t_op			*op;
	long long		cur;
}					t_philo;

/*
** =============================================================================
** Context Functions
** =============================================================================
*/

t_exit	exit_invalid(t_op *op, t_philo **philo, void (*f)(void));
t_exit	exit_valid(t_op *op, t_philo **philo);
void	*routine(void *arg);
void	*monitor(void *arg);

/*
** =============================================================================
** Utility Functions
** =============================================================================
*/

bool	chrono(long long *val);
void	elapse(t_philo *philo, long long begin, long long limit);
bool	console(t_philo *philo, t_cond cond);
void	take_fork(t_philo *philo);
void	put_fork(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

/*
** =============================================================================
** J Functions
** =============================================================================
*/

bool	my_atoi(char **s, int *v);
bool	my_calloc(void **ptr, size_t cnt, size_t n);
void	my_free(void **ptr);
bool	my_isdigit(int c);
bool	my_isspace(int c);
void	*my_memset(void *s, int c, size_t n);
void	my_putchar(char c, int fd);
void	my_putendl(char *s, int fd);
void	my_putnbr(int n, int fd);
void	my_putstr(char *s, int fd);
size_t	my_strlen(const char *s);

#endif
