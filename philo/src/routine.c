/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:26:53 by we                #+#    #+#             */
/*   Updated: 2024/06/06 21:51:36 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_philo *philo, int time_to_eat, long start_time)
{
	if (philo->state == DEAD)
		return ;
	// printf("address: %p\n", (void *)philo);	// Debug
	log_activity(start_time, philo->id, "\033[0;32mis eating\033[0m");
	printf("\n");
	philo->state = EATING;
	if (philo->current_time + time_to_eat > philo->starve_time)
	{
		usleep((philo->starve_time - philo->current_time) * 1000);
		p_die(philo, start_time);
		return ;
	}
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
	if (*philo->left_fork == 0 && *philo->right_fork == 0)
	{
		log_activity(start_time, philo->id,
		"\033[0;33mhas taken a fork\033[0m");
		printf("\n");
		log_activity(start_time, philo->id,
		"\033[0;33mhas taken a fork\033[0m");
		printf("\n");
		*philo->left_fork = philo->id;
		*philo->right_fork = philo->id;
	}
}

void	p_sleep(t_philo *philo, int time_to_sleep, long start_time)
{
	if (philo->state == DEAD)
		return ;
	// printf("address: %p\n", (void *)philo);	// Debug
	log_activity(start_time, philo->id, "\033[0;34mis sleeping\033[0m");
	printf("\n");
	philo->state = SLEEPING;
	if (philo->current_time + time_to_sleep > philo->starve_time)
	{
		usleep((philo->starve_time - philo->current_time) * 1000);
		p_die(philo, start_time);
		return ;
	}
	usleep(time_to_sleep * 1000);
}

void	p_think(t_philo *philo, long start_time)
{
	if (philo->state == DEAD)
		return ;
	// printf("address: %p\n", (void *)philo);	// Debug
	log_activity(start_time, philo->id, "is thinking");
	printf("\n");
	philo->state = THINKING;
}

void	p_die(t_philo *philo, long start_time)
{
	// printf("address: %p\n", (void *)philo);	// Debug
	log_activity(start_time, philo->id, "\033[0;31mdied\033[0m");
	printf("\n");
	philo->state = DEAD;
}
