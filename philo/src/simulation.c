/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:02:42 by we                #+#    #+#             */
/*   Updated: 2024/06/06 21:39:07 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_simulation(t_table *table)
{
	pthread_t	philos[table->philo_count];
	pthread_t	timers[table->philo_count];
	int			initial_count;
	int			i;

	printf("Starting simulation...\n");
	initial_count = table->philo_count;
	i = -1;
	// printf("total_eat_count: %d\n", table->philo_count * table->must_eat_count);	// Debug
	while (++i < initial_count)
	{
		pthread_create(&philos[i], NULL, philo_routine, table);
		pthread_create(&timers[i], NULL, timer, table);
		// pthread_join(philos[i], NULL);	// Debug
	}
	i = -1;
	while (++i < initial_count)
	{
		pthread_join(philos[i], NULL);
		pthread_join(timers[i], NULL);
	}
	printf("Ending simulation...\n");
}

void	*philo_routine(void	*arg)
{
	t_table		*t;
	t_philo		*p;
	int			initial_count;
	static int	i;

	t = (t_table *)arg;
	p = t->philos + i++;
	initial_count = t->philo_count;
	// printf("id: %d\n", p->id);	// Debug
	while (p->state != DEAD && t->philo_count == initial_count &&
		p->eat_count < t->must_eat_count)
	{
		p_think(p, t->start_time);
		while ((*p->left_fork != p->id|| *p->right_fork != p->id)
			&& p->state != DEAD)
			p_take_fork(p, t->start_time);
		// print_forks(t->forks, t->philo_count, 'i');	// Debug
		p_eat(p, t->time_to_eat, t->start_time);
		t->total_eat_count++;
		// printf("time_to_die[%d]: %ld\n", p->id, p->last_eat_time + t->time_to_die - t->start_time);	// Debug
		p_sleep(p, t->time_to_sleep, t->start_time);
	}
	// printf("total_eat_count: %d\n", t->total_eat_count);	// Debug
	return (NULL);
}

void	*timer(void *arg)
{
	t_table		*t;
	t_philo		*p;
	static int	i;

	t = (t_table *)arg;
	p = t->philos + i++;
	while (p->state != DEAD
		&& t->total_eat_count != t->philo_count * t->must_eat_count)
	{
		p->current_time = get_time_ms() - t->start_time;
		p->starve_time = p->last_eat_time + t->time_to_die - t->start_time;
		// printf("current_time[%d]: %ld\n", p->id, p->current_time);	// Debug
		// printf("starve_time[%d]: %ld\n", p->id, p->starve_time);	// Debug
		if (p->current_time > p->starve_time)
		{
			pthread_mutex_lock(&t->monitor);
			p_die(p, t->start_time);
			t->philo_count--;
			pthread_mutex_unlock(&t->monitor);
		}
	}
	return (NULL);
}
