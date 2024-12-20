/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:40:27 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/29 14:00:21 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	log_activity(t_table *table, int id, char *msg)
{
	long	current_time;

	current_time = get_time_ms() - WAIT;
	pthread_mutex_lock(&table->log_mutex);
	if (is_end_sim(table))
	{
		pthread_mutex_unlock(&table->log_mutex);
		return ;
	}
	printf("%ld %d %s\n\n", current_time - table->start_time, id, msg);
	pthread_mutex_unlock(&table->log_mutex);
}

void	usleep_ms(long ms)
{
	long	start_time;

	start_time = get_time_ms();
	while ((get_time_ms() - start_time) < ms)
		usleep(500);
}

long	get_time_ms(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
