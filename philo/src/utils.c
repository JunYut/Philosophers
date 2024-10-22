/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:40:27 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/22 14:45:44 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	log_activity(t_mutex *log_mutex, long start_time, int id, char *msg)
{
	long	current_time;

	current_time = get_time_ms() - WAIT;
	pthread_mutex_lock(log_mutex);
	printf("%ldms: %d %s\n\n", current_time - start_time, id, msg);
	pthread_mutex_unlock(log_mutex);
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
