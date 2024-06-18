/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:02:42 by we                #+#    #+#             */
/*   Updated: 2024/06/18 08:53:38 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_simulation(t_table *table)
{
	pthread_t	*philos;
	pthread_t	*timers;
	int			i;

	printf("Starting simulation...\n\n");
	philos = (pthread_t *)ft_malloc(sizeof(pthread_t) * table->philo_count);
	timers = (pthread_t *)ft_malloc(sizeof(pthread_t) * table->philo_count);
	i = -1;
	while (++i < table->philo_count)
	{
		pthread_create(&philos[i], NULL, philo_routine, table);
		pthread_create(&timers[i], NULL, timer, table);
	}
	i = -1;
	while (++i < table->philo_count)
	{
		pthread_join(philos[i], NULL);
		pthread_join(timers[i], NULL);
	}
	printf("Ending simulation...\n\n");
	printf("total_eat_count: %d/%d\n", table->total_eat_count,
		table->philo_count * table->must_eat_count);
	free(philos);
	free(timers);
}

void	*philo_routine(void	*arg)
{
	t_table		*t;
	t_philo		*p;
	static int	i;

	t = (t_table *)arg;
	p = t->philos + i++;
	if (t->philo_count == 1)
	{
		usleep(t->time_to_die * 1000);
		p_die(p, t, t->start_time);
		return (NULL);
	}
	while (p->state != DEAD && !t->end_sim && p->eat_count < t->must_eat_count)
	{
		p_think(p, t, t->start_time);
		while (p->state != DEAD && !t->end_sim
			&& (*p->r_fork_status != p->id || *p->l_fork_status != p->id))
			p_take_fork(p, t, t->start_time);
		// print_forks(t->forks_status, t->philo_count, 'i');	// Debug
		p_eat(p, t);
		p_sleep(p, t);
	}
	return (NULL);
}

void	*timer(void *arg)
{
	t_table		*t;
	t_philo		*p;
	static int	i;

	t = (t_table *)arg;
	p = t->philos + i++;
	while (p->state != DEAD && !t->end_sim && p->eat_count < t->must_eat_count)
	{
		p->current_time = get_time_ms() - t->start_time;
		// printf("current_time[%d]: %ld\n", p->id, p->current_time);	// Debug
		if (p->state != DEAD && p->current_time >= p->starve_time)
		{
			p_die(p, t, t->start_time);
		}
	}
	return (NULL);
}
