/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:26:53 by we                #+#    #+#             */
/*   Updated: 2024/06/05 09:54:35 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_philo *philo, int time_to_eat, long start_time)
{
	log_activity(start_time, philo->id, "is eating");
	philo->state = EATING;
	usleep(time_to_eat * 1000);
	philo->eat_count++;
	*philo->left_fork = 0;
	*philo->right_fork = 0;
	philo->last_eat_time = get_time_ms();
}

// '0' represents a fork that is not being used
// 'id' represents a fork that is being used by a philosopher
void	p_take_fork(t_philo *philo, long start_time)
{
	if (*philo->left_fork == 0)
	{
		log_activity(start_time, philo->id, "has taken a fork");
		*philo->left_fork = philo->id;
	}
	if (*philo->right_fork == 0)
	{
		log_activity(start_time, philo->id, "has taken a fork");
		*philo->right_fork = philo->id;
	}
}

void	p_sleep(t_philo *philo, int time_to_sleep, long start_time)
{
	log_activity(start_time, philo->id, "is sleeping");
	philo->state = SLEEPING;
	usleep(time_to_sleep * 1000);
}

void	p_think(t_philo *philo, long start_time)
{
	log_activity(start_time, philo->id, "is thinking");
	philo->state = THINKING;
}

void	p_die(t_philo *philo, long start_time)
{
	log_activity(start_time, philo->id, "died");
	philo->state = DEAD;
}
