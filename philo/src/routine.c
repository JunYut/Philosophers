/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:26:53 by we                #+#    #+#             */
/*   Updated: 2024/06/06 23:30:30 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_philo *p, t_table *t)
{
	if (p->state == DEAD)
		return ;
	log_activity(t->start_time, p->id, "\033[0;32mis eating\033[0m");
	printf("\n");
	p->state = EATING;
	if (p->current_time + t->time_to_eat > p->starve_time)
	{
		// pthread_mutex_lock(&t->state_mutex);
		// printf("starve_time: %ld\n", p->starve_time);	// Debug
		usleep((p->starve_time - p->current_time) * 1000);
		printf("p_eat[%d]\n", p->id);	// Debug
		p_die(p, t->start_time, &t->philo_count, &p->state_mutex);
		// pthread_mutex_unlock(&t->state_mutex);
		return ;
	}
	usleep(t->time_to_eat * 1000);
	p->eat_count++;
	t->total_eat_count++;
	*p->left_fork = 0;
	*p->right_fork = 0;
	p->last_eat_time = get_time_ms();
}

// '0' represents a fork that is not being used
// 'id' represents a fork that is being used by a philosopher
void	p_take_fork(t_philo *p, long start)
{
	if (p->state == DEAD)
		return ;
	if (*p->left_fork == 0 && *p->right_fork == 0)
	{
		log_activity(start, p->id,
		"\033[0;33mhas taken a fork\033[0m");
		printf("\n");
		*p->left_fork = p->id;
		if (p->state == DEAD)
			return ;
		log_activity(start, p->id,
		"\033[0;33mhas taken a fork\033[0m");
		printf("\n");
		*p->right_fork = p->id;
	}
}

void	p_sleep(t_philo *p, t_table *t)
{
	if (p->state == DEAD)
		return ;
	log_activity(t->start_time, p->id, "\033[0;34mis sleeping\033[0m");
	printf("\n");
	p->state = SLEEPING;
	if (p->current_time + t->time_to_sleep > p->starve_time)
	{
		usleep((p->starve_time - p->current_time) * 1000);
		printf("p_sleep[%d]\n", p->id);	// Debug
		p_die(p, t->start_time, &t->philo_count, &p->state_mutex);
		return ;
	}
	usleep(t->time_to_sleep * 1000);
}

void	p_think(t_philo *p, long start)
{
	if (p->state == DEAD)
		return ;
	log_activity(start, p->id, "is thinking");
	printf("\n");
	p->state = THINKING;
}

void	p_die(t_philo *p, long start, int *p_count, pthread_mutex_t *m)
{
	pthread_mutex_lock(m);
	if (p->state == DEAD)
		return ;
	log_activity(start, p->id, "\033[0;31mdied\033[0m");
	printf("\n");
	p->state = DEAD;
	*p_count -= 1;
	pthread_mutex_unlock(m);
}
