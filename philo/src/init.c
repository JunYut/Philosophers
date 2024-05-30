/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:02:39 by we                #+#    #+#             */
/*   Updated: 2024/05/30 11:52:20 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_env(t_table *table, int philo_count)
{
	table->forks = init_forks(philo_count);
	table->philos = init_philos(table->forks, philo_count);
	table->start_time = get_time_ms();
	table->philo_count = philo_count;
	pthread_mutex_init(&table->monitor, NULL);
}

t_philo	*init_philos(char *forks, int count)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ft_malloc(sizeof(t_philo) * count);
	i = -1;
	while (++i < count)
	{
		philos[i].id = i + 1;
		philos[i].state = THINKING;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % count];
		philos[i].eat_count = 0;
	}
	return (philos);
}

char	*init_forks(int count)
{
	char	*fork;

	fork = (char *)ft_malloc(count);
	memset(fork, 1, count);
	return (fork);
}

void	clean_up(t_table *table)
{
	free(table->philos);
	free(table->forks);
}
