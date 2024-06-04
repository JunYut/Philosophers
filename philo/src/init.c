/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:02:39 by we                #+#    #+#             */
/*   Updated: 2024/06/04 11:02:38 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_env(t_table *table, char *argv[])
{
	printf("Initializing environment...\n");
	table->philo_count = ft_atoi(argv[1]);
	table->forks = init_forks(table->philo_count);
	print_forks(table->forks, table->philo_count);	// Debug
	table->philos = init_philos(table->forks, table->philo_count);
	print_forks(table->forks, table->philo_count);	// Debug
	table->start_time = get_time_ms();
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->must_eat_count = ft_atoi(argv[5]);
	else
		table->must_eat_count = 5;
	pthread_mutex_init(&table->monitor, NULL);
}

t_philo	*init_philos(int *forks, int count)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ft_malloc(sizeof(t_philo) * count);
	i = -1;
	printf("Initializing philosophers...\n");	// Debug
	print_forks(forks, count);	// Debug
	while (++i < count)
	{
		printf("fork[5]: %d\n", forks[4]);	// Debug
		// printf("fork[%d]: %p\n", i, (void *)&forks[i]);	// Debug
		// printf("fork[%d]: %d\n", i, forks[i]);	// Debug
		philos[i].id = i + 1;
		philos[i].state = THINKING;
		if (i == 0)
			philos[i].right_fork = &forks[count - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		// printf("fork[%d]: %p\n", i, (void *)philos[i].right_fork);	// Debug
		// printf("fork[%d]: %d\n", i, *philos[i].right_fork);	// Debug
		// printf("fork[%p]: %d\n", (void *)philos[i].right_fork, *philos[i].right_fork);	// Debug
		philos[i].left_fork = &forks[i];
		// printf("fork[%p]: %d\n\n", (void *)philos[i].right_fork, *philos[i].right_fork);	// Debug
		philos[i].eat_count = 0;
	}
	printf("\n");
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
