/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:04:40 by we                #+#    #+#             */
/*   Updated: 2024/10/18 12:04:52 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_end_sim(t_table *table)
{
	pthread_mutex_lock(&table->end_mutex);
	if (table->end_sim)
	{
		pthread_mutex_unlock(&table->end_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->end_mutex);
	return (0);
}
