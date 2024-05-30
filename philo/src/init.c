/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:02:39 by we                #+#    #+#             */
/*   Updated: 2024/05/30 10:57:27 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_env(t_table *table, int philo_count)
{
	table->philo = init_philos(philo_count);
	table->fork = (char *)ft_malloc(philo_count);
	table->start_time = get_time_ms();
	table->philo_count = philo_count;
	memset(table->fork, 1, philo_count);
}

t_philo	*init_philos(int count)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ft_malloc(sizeof(t_philo) * count);
	i = -1;
	while (++i < count)
	{
		philos[i].id = i + 1;
		philos[i].state = THINKING;
		philos[i].left_fork = 1;
		philos[i].right_fork = 1;
		philos[i].eat_count = 0;
	}
	return (philos);
}

void	clean_up(t_table *table)
{
	free(table->philo);
	free(table->fork);
}
