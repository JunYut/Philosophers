/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:02:42 by we                #+#    #+#             */
/*   Updated: 2024/06/06 12:11:35 by we               ###   ########.fr       */
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
	// printf("philo_count: %d\n", t->philo_count);	// Debug
	// printf("state: %d\n", p->state);	// Debug
	// printf("id: %d\n", p->id);	// Debug
	// printf("left_fork (%p): %d\n", (void *)(p->left_fork), *p->left_fork);	// Debug
	// printf("right_fork (%p): %d\n", (void *)(p->right_fork), *p->right_fork);	// Debug
	// printf("must_eat_count: %d\n", t->must_eat_count);	// Debug
	while (p->state != DEAD && t->philo_count == initial_count &&
		p->eat_count < t->must_eat_count)
	{
		p_think(p, t->start_time);
		while (*p->left_fork != p->id|| *p->right_fork != p->id)
			p_take_fork(p, t->start_time);
		print_forks(t->forks, t->philo_count, 'i');	// Debug
		p_eat(p, t->time_to_eat, t->start_time);
		t->total_eat_count++;
		// printf("time_to_die[%d]: %ld\n", p->id, p->last_eat_time + t->time_to_die - t->start_time);	// Debug
		p_sleep(p, t->time_to_sleep, t->start_time);
	}
	// printf("eat_count: %d\n", p->eat_count);	// Debug
	// printf("total_eat_count: %d\n", t->total_eat_count);	// Debug
	return (NULL);
}

void	*timer(void *arg)
{
	t_table		*t;
	t_philo		*p;
	long		last_eat_time;
	long		time_to_die;
	static int	i;

	t = (t_table *)arg;
	p = t->philos + i++;
	while (p->state != DEAD
		&& t->total_eat_count != t->philo_count * t->must_eat_count)
	{
		last_eat_time = p->last_eat_time - t->start_time;
		time_to_die = last_eat_time + t->time_to_die;
		// printf("last_eat_time: %ld\n", p->last_eat_time);	// Debug
		// printf("last_eat_time: %ld\n", last_eat_time);	// Debug
		// printf("time_to_die: %ld\n", time_to_die);	// Debug
		if (last_eat_time > time_to_die)
		{
			pthread_mutex_lock(&t->monitor);
			p_die(p, t->start_time);
			t->philo_count--;
			pthread_mutex_unlock(&t->monitor);
		}
	}
	return (NULL);
}
