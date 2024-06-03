/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:26:53 by we                #+#    #+#             */
/*   Updated: 2024/06/03 15:35:29 by we               ###   ########.fr       */
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
// 'id' represents a fork that is being used by a philosopher
void	p_take_fork(t_philo *philo, long start_time)
{
	if (*philo->left_fork == 0)
	{
		log_activity(start_time, philo->id, "has taken a fork");
		*philo->left_fork = philo->id;
		printf("left_fork: %d\n", *philo->left_fork);	// Debug
	}
	if (*philo->right_fork == 0)
	{
		log_activity(start_time, philo->id, "has taken a fork");
		*philo->right_fork = philo->id;
		printf("right_fork: %d\n", *philo->right_fork);	// Debug
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
