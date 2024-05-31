/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:26:53 by we                #+#    #+#             */
/*   Updated: 2024/05/31 17:57:09 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_philo *philo, int time_to_eat, long start_time)
{
	log_activity(start_time, philo->id, "is eating");
	philo->state = EATING;
	usleep(time_to_eat);
	philo->eat_count++;
	*philo->left_fork = 0;
	*philo->right_fork = 0;
}

// '0' represents a fork that is not being used
// '3' represents being used by odd numbered philosopher
// '2' represents being used by even numbered philosopher
void	p_take_fork(t_philo *philo, long start_time)
{
	if (philo->left_fork == 0)
	{
		log_activity(start_time, philo->id, "has taken a fork");
		*philo->left_fork = philo->id % 2 + 2;
	}
	if (philo->right_fork == 0)
	{
		log_activity(start_time, philo->id, "has taken a fork");
		*philo->right_fork = philo->id % 2 + 2;
	}
}

void	p_sleep(t_philo *philo, int time_to_sleep, long start_time)
{
	log_activity(start_time, philo->id, "is sleeping");
	philo->state = SLEEPING;
	usleep(time_to_sleep);
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
