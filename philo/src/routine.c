/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:45:53 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/29 22:01:06 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_take_forks(t_philo *philo, t_table *table)
{
	if (table->num_of_philo == 1 || table->must_eat_count == 0)
	{
		usleep_ms(table->time_to_die);
		return ;
	}
	if (!is_end_sim(table))
		pthread_mutex_lock(philo->left_fork);
	log_activity(table, philo->id, "has taken a fork");
	if (!is_end_sim(table))
		pthread_mutex_lock(philo->right_fork);
	log_activity(table, philo->id, "has taken a fork");
}

void	p_eat(t_philo *philo, t_table *table)
{
	log_activity(table, philo->id, "is eating");
	pthread_mutex_lock(&philo->last_eat_mutex);
	philo->last_eat_time = get_time_ms();
	pthread_mutex_unlock(&philo->last_eat_mutex);
	usleep_ms(table->time_to_eat);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->eat_count += 1;
	pthread_mutex_unlock(&philo->eat_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	p_sleep(t_philo *philo, t_table *table)
{
	log_activity(table, philo->id, "is sleeping");
	usleep_ms(table->time_to_sleep);
}

void	p_think(t_philo *philo, t_table *table)
{
	log_activity(table, philo->id, "is thinking");
}

void	p_die(t_philo *philo, t_table *table)
{
	log_activity(table, philo->id, "died");
}
