/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:02:39 by we                #+#    #+#             */
/*   Updated: 2024/06/05 11:17:11 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_env(t_table *table, char *argv[])
{
	printf("Initializing environment...\n");
	table->philo_count = ft_atoi(argv[1]);
	table->forks = init_forks(table->philo_count);
	table->philos = init_philos(table->forks, table->philo_count);
	table->start_time = get_time_ms();
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->must_eat_count = ft_atoi(argv[5]);
	else
		table->must_eat_count = 5;
	table->total_eat_count = 0;
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
		philos[i].last_eat_time = get_time_ms();
		if (i == 0)
			philos[i].right_fork = &forks[count - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		philos[i].left_fork = &forks[i];
		// printf("id: %d\n", philos[i].id);	// Debug
		// printf("left_fork: %p\n", (void *)philos[i].left_fork);	// Debug
		// printf("right_fork: %p\n\n", (void *)philos[i].right_fork);	// Debug
		philos[i].eat_count = 0;
	}
	return (philos);
}

// '0' represents a fork that is not being used
int	*init_forks(int count)
{
	int	*forks;
	int	i;

	forks = (int *)ft_malloc(count);
	i = -1;
	while (++i < count)
		forks[i] = 0;
	return (forks);
}

void	clean_up(t_table *table)
{
	free(table->philos);
	free(table->forks);
}
