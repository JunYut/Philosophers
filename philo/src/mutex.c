/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:04:40 by we                #+#    #+#             */
/*   Updated: 2024/10/18 12:08:20 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_end_sim(t_table *table)
{
	pthread_mutex_lock(&table->end_mutex);
	if (table->end_sim)
	{
		pthread_mutex_unlock(&table->end_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->end_mutex);
	return (0);
}

int	is_starving(t_philo *philo)
{
	pthread_mutex_lock(&philo->starve_mutex);
	if (philo->starve_time < get_time_ms())
	{
		pthread_mutex_unlock(&philo->starve_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->starve_mutex);
	return (0);
}
