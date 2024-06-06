/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:26:53 by we                #+#    #+#             */
/*   Updated: 2024/06/06 18:33:14 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_philo *p, int time_to_eat, long start, pthread_mutex_t *m)
{
	(void)m;
	// pthread_mutex_lock(m);
	if (p->state == DEAD)
		return ;
	log_activity(start, p->id, "\033[0;32mis eating\033[0m");
	printf("\n");
	p->state = EATING;
	usleep(time_to_eat * 1000);
	p->eat_count++;
	*p->left_fork = 0;
	*p->right_fork = 0;
	p->last_eat_time = get_time_ms();
	// pthread_mutex_unlock(m);
}

// '0' represents a fork that is not being used
// 'id' represents a fork that is being used by a philosopher
void	p_take_fork(t_philo *p, long start, pthread_mutex_t *m)
{
	pthread_mutex_lock(m);
	if (p->state == DEAD)
		return ;
	if (*p->left_fork == 0 && *p->right_fork == 0)
	{
		log_activity(start, p->id,
		"\033[0;33mhas taken a fork\033[0m");
		log_activity(start, p->id,
		"\033[0;33mhas taken a fork\033[0m");
		printf("\n");
		*p->left_fork = p->id;
		*p->right_fork = p->id;
	}
	pthread_mutex_unlock(m);
}

void	p_sleep(t_philo *p, int time_to_sleep, long start, pthread_mutex_t *m)
{
	if (p->state == DEAD)
		return ;
	// pthread_mutex_lock(m);
	log_activity(start, p->id, "\033[0;34mis sleeping\033[0m");
	printf("\n");
	p->state = SLEEPING;
	usleep(time_to_sleep * 1000);
	// pthread_mutex_unlock(m);
	(void)m;
}

void	p_think(t_philo *p, long start, pthread_mutex_t *m)
{
	if (p->state == DEAD)
		return ;
	// pthread_mutex_lock(m);
	log_activity(start, p->id, "is thinking");
	printf("\n");
	p->state = THINKING;
	// pthread_mutex_unlock(m);
	(void)m;
}

void	p_die(t_philo *p, long start, pthread_mutex_t *m)
{
	(void)m;
	log_activity(start, p->id, "\033[0;31mdied\033[0m");
	printf("\n");
	p->state = DEAD;
}
