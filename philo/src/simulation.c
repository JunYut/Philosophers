/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:02:42 by we                #+#    #+#             */
/*   Updated: 2024/06/13 17:03:29 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_simulation(t_table *table)
{
	pthread_t	philos[table->philo_count];
	pthread_t	timers[table->philo_count];
	int			i;

	printf("Starting simulation...\n\n");
	i = -1;
	while (++i < table->init_count)
	{
		pthread_create(&philos[i], NULL, philo_routine, table);
		pthread_create(&timers[i], NULL, timer, table);
	}
	i = -1;
	while (++i < table->init_count)
	{
		pthread_join(philos[i], NULL);
		pthread_join(timers[i], NULL);
	}
	printf("total_eat_count: %d\n\n", table->total_eat_count);
	printf("Ending simulation...\n");
}

void	*philo_routine(void	*arg)
{
	t_table		*t;
	t_philo		*p;
	static int	i;

	t = (t_table *)arg;
	p = t->philos + i++;
	while (p->state != DEAD && p->eat_count < t->must_eat_count
		&& t->philo_count == t->init_count)
	{
		p_think(p, t->start_time);
		while (p->state != DEAD
			&& (*p->r_fork_status != p->id || *p->l_fork_status != p->id)
			&& t->philo_count == t->init_count)
			p_take_fork(p, t, t->start_time);
		print_forks(t->forks_status, t->init_count, 'i');	// Debug
		p_eat(p, t);
		p_sleep(p, t);
	}
	// printf("total_eat_count[%d]: %d\n", p->id, t->total_eat_count);	// Debug
	return (NULL);
}

void	*timer(void *arg)
{
	t_table		*t;
	t_philo		*p;
	static int	i;

	t = (t_table *)arg;
	p = t->philos + i++;
	while (p->state != DEAD && p->eat_count < t->must_eat_count
		&& t->philo_count == t->init_count)
	{
		p->current_time = get_time_ms() - t->start_time;
		// printf("current_time[%d]: %ld\n", p->id, p->current_time);	// Debug
		if (p->state != DEAD && p->current_time > p->starve_time)
		{
			p_die(p, t, t->start_time);
		}
	}
	return (NULL);
}
