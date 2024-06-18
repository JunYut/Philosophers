/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:21:15 by we                #+#    #+#             */
/*   Updated: 2024/06/18 11:06:37 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	log_activity(long start_time, int id, char *msg)
{
	long	current_time;

	current_time = get_time_ms();
	printf("%ldms: %d %s\n\n", current_time - start_time, id, msg);
}

void	usleep_ms(long ms)
{
	long	start_time;

	start_time = get_time_ms();
	while ((get_time_ms() - start_time) < ms)
		usleep(500);
	// printf("time: %ld\n", get_time_ms() - start_time);	// Debug
}

long	get_time_ms(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	*ft_malloc(size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (!new_ptr)
	{
		write(2, "malloc failed\n", 14);
		return (NULL);
	}
	return (new_ptr);
}

long	ft_atoi(const char *str)
{
	long	num;
	int		len;
	int		i;

	len = -1;
	while (str[++len])
		;
	num = 0;
	i = -1;
	if (str[0] == '-')
		++i;
	while (++i < len)
	{
		num = num * 10 + str[i] - '0';
	}
	if (str[0] == '-')
		num *= -1;
	return (num);
}

