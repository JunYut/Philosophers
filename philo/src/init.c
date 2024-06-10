/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:02:39 by we                #+#    #+#             */
/*   Updated: 2024/06/10 09:46:00 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_env(t_table *t, char *argv[])
{
	printf("Initializing environment...\n\n");
	t->philo_count = ft_atoi(argv[1]);
	t->init_count = t->philo_count;
	t->forks = (t_mutex *)ft_malloc(sizeof(t_mutex) * t->philo_count);
	t->forks_status = (int *)ft_malloc(sizeof(int) * t->philo_count);
	t->philos = (t_philo *)ft_malloc(sizeof(t_philo) * t->philo_count);
	t->start_time = get_time_ms();
	t->time_to_die = ft_atoi(argv[2]);
	t->time_to_eat = ft_atoi(argv[3]);
	t->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		t->must_eat_count = ft_atoi(argv[5]);
	else
		t->must_eat_count = 5;
	init_forks(t->forks, t->forks_status, t->philo_count);
	init_philos(t->philos, t->philo_count, t);
	printf("philosopher_count: %d\n\n", t->philo_count);
	printf("time_to_die: %d\n\n", t->time_to_die);
	printf("time_to_eat: %d\n\n", t->time_to_eat);
	printf("time_to_sleep: %d\n\n", t->time_to_sleep);
	printf("must_eat_count: %d\n\n", t->must_eat_count);
	t->total_eat_count = 0;
}

void	init_philos(t_philo *p, int count, t_table *t)
{
	int		i;

	i = -1;
	while (++i < count)
	{
		p[i].id = i + 1;
		p[i].state = THINKING;
		if (i == 0)
		{
			p[i].right_fork = &t->forks[count - 1];
			p[i].r_fork_status = &t->forks_status[count - 1];
		}
		else
		{
			p[i].right_fork = &t->forks[i - 1];
			p[i].r_fork_status = &t->forks_status[i - 1];
		}
		p[i].left_fork = &t->forks[i];
		p[i].l_fork_status = &t->forks_status[i];
		p[i].last_eat_time = get_time_ms();
		p[i].starve_time = t->time_to_die;
		p[i].eat_count = 0;
		pthread_mutex_init(&p[i].state_mutex, NULL);
	}
}

// '0' represents a fork that is not being used
void	init_forks(t_mutex *forks, int *forks_status, int count)
{
	int				i;

	i = -1;
	while (++i < count)
	{
		pthread_mutex_init(&forks[i], NULL);
		forks_status[i] = 0;
	}
}

void	clean_up(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->init_count)
	{
		pthread_mutex_destroy(&table->philos[i].state_mutex);
		pthread_mutex_destroy(&table->forks[i]);
	}
	free(table->philos);
	free(table->forks);
	free(table->forks_status);
}
