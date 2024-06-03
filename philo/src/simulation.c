/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:02:42 by we                #+#    #+#             */
/*   Updated: 2024/06/03 15:25:53 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_simulation(t_table *table)
{
	pthread_t	threads[table->philo_count];
	t_table *t = table;
	int			i;

	print_forks(t->forks, t->philo_count);	// Debug
	i = -1;
	while (++i < table->philo_count)
	{
		pthread_create(&threads[i], NULL, philo_routine, t);
		t->philos++;
		pthread_join(threads[i], NULL);
	}
	t->philos -= i;
	i = -1;
	while (++i < table->philo_count)
		pthread_join(threads[i], NULL);
}

void	*philo_routine(void	*arg)
{
	t_table		*t;
	t_philo		*p;
	int			i;

	t = (t_table *)arg;
	p = t->philos;
	i = -1;
	printf("id: %d\n", p->id);	// Debug
	printf("left_fork (%p): %d\n", (void *)(p->left_fork), *p->left_fork);	// Debug
	printf("right_fork (%p): %d\n", (void *)(p->right_fork), *p->right_fork);	// Debug
	printf("must_eat_count: %d\n", t->must_eat_count);	// Debug
	while ((p->state != DEAD || p->eat_count < t->must_eat_count)
		&& ++i < t->must_eat_count)
	{
		p_think(p, t->start_time);
		while (*p->left_fork != p->id|| *p->right_fork != p->id)
			p_take_fork(p, t->start_time);
		print_forks(t->forks, t->philo_count);	// Debug
		p_eat(p, t->time_to_eat, t->start_time);
		p_sleep(p, t->time_to_sleep, t->start_time);
	}
	return (NULL);
}
