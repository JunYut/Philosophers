/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:02:39 by we                #+#    #+#             */
/*   Updated: 2024/05/30 10:35:43 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_env(t_table *table, int philo_count)
{
	table->philo = (t_philo *)ft_malloc(sizeof(t_philo) * philo_count);
	table->fork = (char *)ft_malloc(philo_count);
	table->start_time = get_time_ms();
	table->philo_count = philo_count;
	memset(table->fork, 1, philo_count);
}

void	clean_up(t_table *table)
{
	free(table->philo);
	free(table->fork);
}
