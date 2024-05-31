/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:02:42 by we                #+#    #+#             */
/*   Updated: 2024/05/31 16:31:57 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_sim(t_table *table)
{

}

void	*philo_routine(void	*arg)
{
	t_table		*t;
	t_philo		*p;

	t = (t_table *)arg;
	p = t->philos;
	while (p->state != DEAD || p->eat_count < t->must_eat_count)
	{
		p_think(p, t->start_time);
		while (p->left_fork != 0 || p->right_fork != 0)
			p_take_fork(p, t->start_time);
		p_eat(p, t->time_to_eat, t->start_time);
		p_sleep(p, t->time_to_sleep, t->start_time);
	}
	return (NULL);
}