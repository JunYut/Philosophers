/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:21:15 by we                #+#    #+#             */
/*   Updated: 2024/05/30 10:31:26 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	log_activity(long start_time, int id, char *msg)
{
	printf("%ldms: %d %s\n", get_time_ms() - start_time, id, msg);
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
		exit(1);
	}
	return (new_ptr);
}

long	ft_atoi(const char *str)
{
	long	num;
	int		i;

	num = 0;
	i = -1;
	if (str[0] == '-')
		++i;
	while (++i < ft_strlen(str))
	{
		num = num * 10 + str[i] - '0';
	}
	if (str[0] == '-')
		num *= -1;
	return (num);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}
