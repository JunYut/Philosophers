/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:02:42 by we                #+#    #+#             */
/*   Updated: 2024/06/07 16:54:13 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_simulation(t_table *table)
{
	pthread_t	*philos;
	pthread_t	*timers;
	int			i;

	printf("Starting simulation...\n\n");
	philos = (pthread_t *)ft_malloc(sizeof(pthread_t) * table->init_count);
	timers = (pthread_t *)ft_malloc(sizeof(pthread_t) * table->init_count);
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
	printf("total_eat_count: %d\n\n", table->total_eat_count);	// Debug
	printf("Ending simulation...\n");
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
	while (p->state != DEAD && t->philo_count == t->init_count &&
		p->eat_count < t->must_eat_count)
	{
		p_think(p, t->start_time);
		while ((*p->left_fork != p->id || *p->right_fork != p->id)
			&& p->state != DEAD)
		{
			p_take_fork(p, t->start_time);
		}
		print_forks(t->forks, t->philo_count, 'i');	// Debug
		p_eat(p, t);
		p_sleep(p, t);
	}
	printf("eat_count[%d]: %d\n\n", p->id, p->eat_count);	// Debug
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
		p->starve_time = p->last_eat_time + t->time_to_die;
		// printf("current_time[%d]: %ld\n", p->id, p->current_time);	// Debug
		// printf("starve_time[%d]: %ld\n", p->id, p->starve_time);	// Debug
		if (p->state != DEAD && p->current_time > p->starve_time)
		{
			p_die(p, t->start_time, &t->philo_count, &p->state_mutex);
		}
	}
	return (NULL);
}
