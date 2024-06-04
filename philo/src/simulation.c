/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:02:42 by we                #+#    #+#             */
/*   Updated: 2024/06/04 13:06:11 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_simulation(t_table *table)
{
	pthread_t	threads[table->philo_count];
	t_table *t = table;
	int			philo_count;
	int			i;

	printf("Starting simulation...\n");
	print_forks(t->forks, t->philo_count, 'i');	// Debug
	// printf("fork[%d]: %d\n", 5, t->forks[4]);	// Debug
	philo_count = table->philo_count;
	i = -1;
	while (++i < table->philo_count)
	{
		pthread_create(&threads[i], NULL, philo_routine, t);
		t->philos++;
		// pthread_join(threads[i], NULL);	// Debug
	}
	t->philos -= i;
	i = -1;
	while (++i < table->philo_count)
		pthread_join(threads[i], NULL);
	if (philo_count != table->philo_count || table->must_eat_count == 0)
		printf("Ending simulation...\n");
}

void	*philo_routine(void	*arg)
{
	t_table		*t;
	t_philo		*p;
	int			philo_count;
	int			i;

	t = (t_table *)arg;
	p = t->philos;
	philo_count = t->philo_count;
	i = -1;
	// printf("philo_count: %d\n", t->philo_count);	// Debug
	// printf("state: %d\n", p->state);	// Debug
	// printf("id: %d\n", p->id);	// Debug
	// printf("left_fork (%p): %d\n", (void *)(p->left_fork), *p->left_fork);	// Debug
	// printf("right_fork (%p): %d\n", (void *)(p->right_fork), *p->right_fork);	// Debug
	// printf("must_eat_count: %d\n", t->must_eat_count);	// Debug
	while (p->state != DEAD && t->philo_count == philo_count &&
		p->eat_count < t->must_eat_count && ++i < t->must_eat_count)
	{
		p_think(p, t->start_time);
		while (*p->left_fork != p->id|| *p->right_fork != p->id)
			p_take_fork(p, t->start_time);
		print_forks(t->forks, t->philo_count, 'i');	// Debug
		p_eat(p, t->time_to_eat, t->start_time);
		p_sleep(p, t->time_to_sleep, t->start_time);
	}
	return (NULL);
}
