/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:26:53 by we                #+#    #+#             */
/*   Updated: 2024/06/14 15:30:19 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_philo *p, t_table *t)
{
	// printf("before_eat[%d]: %d\n", p->id, p->state);	// Debug
	pthread_mutex_lock(&t->end_sim_mutex);
	if (p->state == DEAD || t->end_sim)
	{
		pthread_mutex_unlock(&t->end_sim_mutex);
		return ;
	}
	pthread_mutex_lock(&p->state_mutex);
	log_activity(t->start_time, p->id, "\033[0;32mis eating\033[0m");
	p->state = EATING;
	pthread_mutex_unlock(&t->end_sim_mutex);
	if (p->current_time + t->time_to_eat >= p->starve_time)
	{
		pthread_mutex_unlock(&p->state_mutex);
		pthread_mutex_unlock(&t->end_sim_mutex);
		if (p->starve_time - p->current_time <= 0)
			p_die(p, t, t->start_time);
		else
			usleep((p->starve_time - p->current_time) * 1000);
		p_die(p, t, t->start_time);
		return ;
	}
	usleep(t->time_to_eat * 1000);
	p->eat_count++;
	t->total_eat_count++;
	p->starve_time = get_time_ms() + t->time_to_die;
	// printf("starve_time[%d]: %ld\n", p->id, p->starve_time - t->start_time);	// Debug
	pthread_mutex_unlock(&p->state_mutex);
}

// '0' represents a fork that is not being used
// 'id' represents a fork that is being used by a philosopher
void	p_take_fork(t_philo *p, t_table *t, long start)
{
	pthread_mutex_lock(&t->end_sim_mutex);
	if (p->state == DEAD || t->end_sim)
	{
		pthread_mutex_unlock(&t->end_sim_mutex);
		return ;
	}
	pthread_mutex_lock(&t->forks_mutex);
	if (*p->r_fork_status == 0 && *p->l_fork_status == 0)
	{
		log_activity(start, p->id, "\033[0;33mhas taken a fork\033[0m");
		pthread_mutex_lock(p->right_fork);
		*p->r_fork_status = p->id;
		log_activity(start, p->id, "\033[0;33mhas taken a fork\033[0m");
		pthread_mutex_lock(p->left_fork);
		*p->l_fork_status = p->id;
	}
	pthread_mutex_unlock(&t->forks_mutex);
	pthread_mutex_unlock(&t->end_sim_mutex);
}

void	p_sleep(t_philo *p, t_table *t)
{
	// printf("before_sleep[%d]: %d\n", p->id, p->state);	// Debug
	if (p->state == DEAD || t->end_sim)
		return ;
	pthread_mutex_lock(&p->state_mutex);
	log_activity(t->start_time, p->id, "\033[0;34mis sleeping\033[0m");
	p->state = SLEEPING;
	if (p->current_time + t->time_to_sleep >= p->starve_time)
	{
		pthread_mutex_unlock(&p->state_mutex);
		if (p->starve_time - p->current_time <= 0)
			p_die(p, t, t->start_time);
		else
			usleep((p->starve_time - p->current_time) * 1000);
		p_die(p, t, t->start_time);
		return ;
	}
	pthread_mutex_unlock(p->right_fork);
	*p->r_fork_status = 0;
	pthread_mutex_unlock(p->left_fork);
	*p->l_fork_status = 0;
	usleep(t->time_to_sleep * 1000);
	pthread_mutex_unlock(&p->state_mutex);
}

void	p_think(t_philo *p, t_table *t, long start)
{
	// printf("before_think[%d]: %d\n", p->id, p->state);	// Debug
	pthread_mutex_lock(&t->end_sim_mutex);
	if (p->state == DEAD || t->end_sim)
	{
		pthread_mutex_unlock(&t->end_sim_mutex);
		return ;
	}
	pthread_mutex_lock(&p->state_mutex);
	log_activity(start, p->id, "is thinking");
	p->state = THINKING;
	pthread_mutex_unlock(&p->state_mutex);
	pthread_mutex_unlock(&t->end_sim_mutex);
}

void	p_die(t_philo *p, t_table *t, long start)
{
	// printf("before_die[%d]: %d\n", p->id, p->state);	// Debug
	pthread_mutex_lock(&t->end_sim_mutex);
	if (p->state == DEAD || t->end_sim)
	{
		pthread_mutex_unlock(&t->end_sim_mutex);
		return ;
	}
	pthread_mutex_lock(&p->state_mutex);
	log_activity(start, p->id, "\033[0;31mdied\033[0m");
	p->state = DEAD;
	pthread_mutex_unlock(&p->state_mutex);
	t->end_sim = 1;
	pthread_mutex_unlock(&t->end_sim_mutex);
}
