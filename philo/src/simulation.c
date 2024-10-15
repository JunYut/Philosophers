/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:02:42 by we                #+#    #+#             */
/*   Updated: 2024/10/15 14:55:58 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_simulation(t_table *table)
{
	pthread_t	*philos;
	int			i;

	printf("Starting simulation...\n\n");
	philos = (pthread_t *)ft_malloc(sizeof(pthread_t) * table->philo_count);
	i = -1;
	while (++i < table->philo_count)
	{
		pthread_create(&philos[i], NULL, philo_routine, table);
	}
	i = -1;
	while (++i < table->philo_count)
	{
		pthread_join(philos[i], NULL);
	}
	printf("Ending simulation...\n\n");
	printf("total_eat_count: %d/%d\n", table->total_eat_count,
		table->philo_count * table->must_eat_count);
	free(philos);
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
		usleep_ms(t->time_to_die);
		p_die(p, t, t->start_time);
		return (NULL);
	}
	while (stop_routine(t, p))
	{
		p_think(p, t, t->start_time);
		while (p->state != DEAD && !t->end_sim
			&& (*p->r_fork_status != p->id || *p->l_fork_status != p->id))
			p_take_fork(p, t, t->start_time);
		p_eat(p, t);
		p_sleep(p, t);
	}
	return (NULL);
}

int	stop_routine(t_table *t, t_philo *p)
{
	if (t->must_eat_count == 0)
		return (1);
	else if (p->state == DEAD || t->end_sim || p->eat_count == t->must_eat_count)
		return (1);
	return (0);
}
