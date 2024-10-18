/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:45:53 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/18 12:03:13 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_philo *philo, t_table *table)
{
	if (is_end_sim(table))
		return ;
	log_activity(table->start_time, philo->id, "is eating");
}

void	p_sleep(t_philo *philo, t_table *table)
{
	if (is_end_sim(table))
		return ;
	log_activity(table->start_time, philo->id, "is sleeping");
}

void	p_think(t_philo *philo, t_table *table)
{
	if (is_end_sim(table))
		return ;
	log_activity(table->start_time, philo->id, "is thinking");
}

void	p_die(t_philo *philo, t_table *table)
{
	log_activity(table->start_time, philo->id, "died");
}
