/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:33:55 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/30 11:52:11 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
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
	char		*left_fork;
	char		*right_fork;
	int			eat_count;
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t	monitor;
	t_philo			*philos;
	char			*forks;
	long			start_time;
	int				philo_count;
}	t_table;

void	schedule(t_table *table);
void	*philo_routine(void *arg);
void	p_eat(t_philo *philo, t_table *table);
void	p_sleep(t_philo *philo, t_table *table);
void	p_think(t_philo *philo, t_table *table);
void	p_die(t_philo *philo, t_table *table);

void	init_env(t_table *table, int philo_count);
t_philo	*init_philos(char *forks, int count);
char	*init_forks(int count);
void	clean_up(t_table *table);

void	log_activity(long start_time, int id, char *msg);
long	get_time_ms(void);
void	*ft_malloc(size_t size);
long	ft_atoi(const char *str);
int		ft_strlen(const char *str);

#endif
