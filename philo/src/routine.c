/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:45:53 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/22 08:59:09 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_philo *philo, t_table *table)
{
	if (is_end_sim(table))
		return ;
	log_activity(table->start_time, philo->id, "is eating");
	usleep_ms(table->time_to_eat);
}

void	p_sleep(t_philo *philo, t_table *table)
{
	if (is_end_sim(table))
		return ;
	log_activity(table->start_time, philo->id, "is sleeping");
	usleep_ms(table->time_to_sleep);
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
