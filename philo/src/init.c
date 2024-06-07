/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:02:39 by we                #+#    #+#             */
/*   Updated: 2024/06/07 16:00:39 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_env(t_table *t, char *argv[])
{
	printf("Initializing environment...\n\n");
	t->philo_count = ft_atoi(argv[1]);
	t->init_count = t->philo_count;
	t->forks = init_forks(t->philo_count);
	t->philos = init_philos(t->forks, t->philo_count, ft_atoi(argv[2]));
	t->start_time = get_time_ms();
	t->time_to_die = ft_atoi(argv[2]);
	t->time_to_eat = ft_atoi(argv[3]);
	t->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		t->must_eat_count = ft_atoi(argv[5]);
	else
		t->must_eat_count = 5;
	printf("philosopher_count: %d\n\n", t->philo_count);
	printf("time_to_die: %d\n\n", t->time_to_die);
	printf("time_to_eat: %d\n\n", t->time_to_eat);
	printf("time_to_sleep: %d\n\n", t->time_to_sleep);
	printf("must_eat_count: %d\n\n", t->must_eat_count);
	t->total_eat_count = 0;
}

t_philo	*init_philos(t_mutex *forks, int count, long starve_time)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ft_malloc(sizeof(t_philo) * count);
	i = -1;
	while (++i < count)
	{
		philos[i].id = i + 1;
		philos[i].state = THINKING;
		if (i == 0)
			philos[i].right_fork = &forks[count - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		philos[i].left_fork = &forks[i];
		philos[i].last_eat_time = get_time_ms();
		philos[i].starve_time = starve_time;
		philos[i].eat_count = 0;
		pthread_mutex_init(&philos[i].state_mutex, NULL);
	}
	return (philos);
}

// '0' represents a fork that is not being used
t_mutex	*init_forks(int count)
{
	t_mutex	*forks;
	int				i;

	forks = (t_mutex *)ft_malloc(sizeof(t_mutex) * count);
	i = -1;
	while (++i < count)
		pthread_mutex_init(&forks[i], NULL);
	return (forks);
}

void	clean_up(t_table *table)
{
	int	i;

	free(table->philos);
	free(table->forks);
	i = -1;
	while (++i < table->init_count)
		pthread_mutex_destroy(&table->philos[i].state_mutex);
}
