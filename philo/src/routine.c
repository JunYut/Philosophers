/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:45:53 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/22 15:27:11 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_take_forks(t_philo *philo, t_table *table)
{
	if (is_end_sim(table))
		return ;
	pthread_mutex_lock(philo->left_fork);
	log_activity(table, philo->id, "has taken a fork");
	if (table->num_of_philo == 1)
	{
		usleep_ms(table->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	log_activity(table, philo->id, "has taken a fork");
}

void	p_eat(t_philo *philo, t_table *table)
{
	if (is_end_sim(table))
		return ;
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
	if (is_end_sim(table))
		return ;
	log_activity(table, philo->id, "is sleeping");
	usleep_ms(table->time_to_sleep);
}

void	p_think(t_philo *philo, t_table *table)
{
	if (is_end_sim(table))
		return ;
	log_activity(table, philo->id, "is thinking");
}

void	p_die(t_philo *philo, t_table *table)
{
	log_activity(table, philo->id, "died");
}
