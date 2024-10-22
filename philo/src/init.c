/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:37:57 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/22 14:29:05 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init(t_table *table, char **av)
{
	table->num_of_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->must_eat_count = -1;
	table->end_sim = false;
	if (av[5])
		table->must_eat_count = ft_atoi(av[5]);
	pthread_mutex_init(&table->end_mutex, NULL);
	pthread_mutex_init(&table->log_mutex, NULL);
	init_fork(table);
	init_philo(table);
	return (1);
}

int	init_philo(t_table *table)
{
	t_philo	*philo;
	int		i;

	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->num_of_philo);
	philo = table->philo;
	i = -1;
	while (++i < table->num_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].eat_count = 0;
		philo[i].left_fork = &table->fork[i];
		philo[i].right_fork = &table->fork[(i + 1) % table->num_of_philo];
		pthread_mutex_init(&philo[i].eat_mutex, NULL);
		pthread_mutex_init(&philo[i].last_eat_mutex, NULL);
	}
	return (1);
}

int	init_fork(t_table *table)
{
	t_mutex	*fork;
	int		i;

	table->fork = (t_mutex *)malloc(sizeof(t_mutex) * table->num_of_philo);
	fork = table->fork;
	i = -1;
	while (++i < table->num_of_philo)
		pthread_mutex_init(&fork[i], NULL);
	return (1);
}

int	clean_up(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_of_philo)
	{
		pthread_mutex_destroy(&table->fork[i]);
		pthread_mutex_destroy(&table->philo[i].eat_mutex);
		pthread_mutex_destroy(&table->philo[i].last_eat_mutex);
	}
	free(table->fork);
	free(table->philo);
	pthread_mutex_destroy(&table->end_mutex);
	pthread_mutex_destroy(&table->log_mutex);
	return (1);
}
