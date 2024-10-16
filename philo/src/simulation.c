/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:56:15 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/16 15:41:36 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	run_simulation(t_table *table)
{
	pthread_t	monitor_thread;
	int	i;

	pthread_create(&monitor_thread, NULL, monitor, table);
	i = -1;
	while (++i < table->num_of_philo)
	{
		pthread_create(&table->philo[i].thread, NULL, start_routine, table);
	}
	pthread_join(monitor_thread, NULL);
	i = -1;
	while (++i < table->num_of_philo)
	{
		pthread_join(table->philo[i].thread, NULL);
	}
	return (1);
}

int	monitor(t_table *table)
{
	(void)table;
	sync_routine(table);
	return (1);
}

void	*start_routine(void *data)
{
	t_table		*t;
	t_philo		*p;
	static int	i;

	t = (t_table *)data;
	p = t->philo + i++;
	sync_routine(t);
	while (1)
	{
		pthread_mutex_lock(&t->end_mutex);
		if (t->end_sim)
			break ;
		pthread_mutex_unlock(&t->end_mutex);
		p_think(p, t);
		p_eat(p, t);
		p_sleep(p, t);
	}
	return (1);
}

void	sync_routine(t_table *table)
{
	long	wait_time;

	wait_time = table->start_time + 1000 - get_time_ms();
	usleep_ms(wait_time);
}
