/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:26:53 by we                #+#    #+#             */
/*   Updated: 2024/05/30 16:10:06 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void	*arg)
{
	t_table		*t;
	t_philo		*p;
	static int	i;

	t = (t_table *)arg;
	p = t->philos;
	if (i == 0 && p[i + 1].state != EATING
		&& p[t->philo_count - 1].state != EATING)
		p_eat(p, t->time_to_eat, t->start_time);
	else if (p[i + 1].state != EATING && p[i - 1].state != EATING)
		p_eat(&p[i], t->time_to_eat, t->start_time);
	p_sleep(&p[i], t->time_to_sleep, t->start_time);
	p_think(&p[i], t->start_time);
	++i;
	if (i == t->philo_count - 1)
		i = 0;
	return (NULL);
}

void	p_eat(t_philo *philo, int time_to_eat, int start_time)
{
	log_activity(start_time, philo->id, "is eating");
	philo->state = EATING;
	*philo->left_fork = 0;
	*philo->right_fork = 0;
	philo->eat_count++;
	usleep(time_to_eat);
	*philo->left_fork = 1;
	*philo->right_fork = 1;
}

void	p_sleep(t_philo *philo, int time_to_sleep, int start_time)
{
	log_activity(start_time, philo->id, "is sleeping");
	philo->state = SLEEPING;
	usleep(time_to_sleep);
}

void	p_think(t_philo *philo, int start_time)
{
	log_activity(start_time, philo->id, "is thinking");
	philo->state = THINKING;
}

void	p_die(t_philo *philo, int start_time)
{
	log_activity(start_time, philo->id, "died");
	philo->state = DEAD;
}
