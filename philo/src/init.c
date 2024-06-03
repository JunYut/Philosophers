/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:02:39 by we                #+#    #+#             */
/*   Updated: 2024/06/03 15:10:05 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_env(t_table *table, char *argv[])
{
	table->philo_count = ft_atoi(argv[1]);
	table->forks = init_forks(table->philo_count);
	table->philos = init_philos(table->forks, table->philo_count);
	table->start_time = get_time_ms();
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (table->must_eat_count)
		table->must_eat_count = ft_atoi(argv[5]);
	pthread_mutex_init(&table->monitor, NULL);
}

t_philo	*init_philos(int *forks, int count)
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

// '0' represents a fork that is not being used
int	*init_forks(int count)
{
	int	*forks;

	forks = (int *)ft_malloc(count);
	memset(forks, 0, count);
	return (forks);
}

void	clean_up(t_table *table)
{
	free(table->philos);
	free(table->forks);
}
