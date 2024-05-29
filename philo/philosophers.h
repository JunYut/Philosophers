/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:33:55 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/29 17:13:24 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

enum e_state
{
	DEAD = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3
};

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	char		state;
	char		left_fork;
	char		right_fork;
	int			eat_count;
}	t_philo;

typedef struct s_table
{
	t_philo	*philo;
	int		*fork;
	int		start_time;
	int		philo_count;
}	t_table;

void	schedule(t_table *table);
void	*philo_routine(void *arg);
void	eat(t_philo *philo);
void	sleep(t_philo *philo);
void	think(t_philo *philo);
void	die(t_philo *philo);
void	log_activity(char *msg, int id);
void	init_env(t_table *table, int philo_count);
void	clean_up(t_table *table);
int		get_time_ms(void);
int		ft_atoi(const char *str);
void	*ft_malloc(void *ptr, size_t size);

#endif
