/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:56:15 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/29 12:57:06 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	run_simulation(t_table *table)
{
	pthread_t	monitor_thread;
	int			i;

	table->start_time = get_time_ms();
	pthread_create(&monitor_thread, NULL, monitor, table);
	i = -1;
	while (++i < table->num_of_philo)
		pthread_create(&table->philo[i].thread, NULL, start_routine, table);
	pthread_join(monitor_thread, NULL);
	i = -1;
	while (++i < table->num_of_philo)
		pthread_join(table->philo[i].thread, NULL);
	return (1);
}

void	*monitor(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	sync_routine(table);
	while (!is_end_sim(table))
	{
		i = -1;
		while (++i < table->num_of_philo)
		{
			if (is_starving(table, table->philo + i) || all_ate_enough(table))
			{
				pthread_mutex_lock(&table->end_mutex);
				table->end_sim = true;
				pthread_mutex_unlock(&table->end_mutex);
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	*start_routine(void *data)
{
	t_table		*t;
	t_philo		*p;
	static int	i;

	t = (t_table *)data;
	pthread_mutex_lock(&t->philo_mutex);
	p = t->philo + i++;
	pthread_mutex_unlock(&t->philo_mutex);
	pthread_mutex_lock(&p->last_eat_mutex);
	p->last_eat_time = t->start_time + WAIT;
	pthread_mutex_unlock(&p->last_eat_mutex);
	sync_routine(t);
	if (p->id % 2 == 0)
		usleep_ms(DELAY);
	while (!is_end_sim(t))
	{
		p_take_forks(p, t);
		p_eat(p, t);
		p_sleep(p, t);
		p_think(p, t);
	}
	return (NULL);
}

void	sync_routine(t_table *table)
{
	long	wait_time;

	wait_time = table->start_time + WAIT - get_time_ms();
	usleep_ms(wait_time);
}
