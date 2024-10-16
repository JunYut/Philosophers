/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:45:53 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/16 15:26:07 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&table->end_mutex);
	if (table->end_sim)
		return ;
	pthread_mutex_unlock(&table->end_mutex);
	log_activity(table->start_time, philo->id, "is eating");
}

void	p_sleep(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&table->end_mutex);
	if (table->end_sim)
		return ;
	pthread_mutex_unlock(&table->end_mutex);
	log_activity(table->start_time, philo->id, "is sleeping");
}

void	p_think(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&table->end_mutex);
	if (table->end_sim)
		return ;
	pthread_mutex_unlock(&table->end_mutex);
	log_activity(table->start_time, philo->id, "is thinking");
}

void	p_die(t_philo *philo, t_table *table)
{
	log_activity(table->start_time, philo->id, "died");
}
