/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:26:53 by we                #+#    #+#             */
/*   Updated: 2024/06/05 11:25:18 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_philo *philo, int time_to_eat, long start_time)
{
	if (philo->state == DEAD)
		return ;
	printf("address: %p\n", (void *)philo);	// Debug
	log_activity(start_time, philo->id, "is eating");
	printf("\n");
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
	if (philo->state == DEAD)
		return ;
	if (*philo->left_fork == 0)
	{
		printf("address: %p\n", (void *)philo);	// Debug
		log_activity(start_time, philo->id, "has taken a fork");
		printf("\n");
		*philo->left_fork = philo->id;
	}
	if (*philo->right_fork == 0)
	{
		printf("address: %p\n", (void *)philo);	// Debug
		log_activity(start_time, philo->id, "has taken a fork");
		printf("\n");
		*philo->right_fork = philo->id;
	}
}

void	p_sleep(t_philo *philo, int time_to_sleep, long start_time)
{
	if (philo->state == DEAD)
		return ;
	printf("address: %p\n", (void *)philo);	// Debug
	log_activity(start_time, philo->id, "is sleeping");
	printf("\n");
	philo->state = SLEEPING;
	usleep(time_to_sleep * 1000);
}

void	p_think(t_philo *philo, long start_time)
{
	if (philo->state == DEAD)
		return ;
	printf("address: %p\n", (void *)philo);	// Debug
	log_activity(start_time, philo->id, "is thinking");
	printf("\n");
	philo->state = THINKING;
}

void	p_die(t_philo *philo, long start_time)
{
	printf("address: %p\n", (void *)philo);	// Debug
	log_activity(start_time, philo->id, "died");
	printf("\n");
	philo->state = DEAD;
}
