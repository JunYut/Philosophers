/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:33:27 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/18 12:04:15 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

# define DEBUG "printf"

typedef pthread_mutex_t	t_mutex;

// left_fork and right_fork are pointers, not allocated memory
typedef struct s_philo
{
	int			id;
	int			eat_count;
	long		starve_time;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_mutex		starve_mutex;
	pthread_t	thread;
}	t_philo;

typedef struct s_table
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat_count;
	long	start_time;
	bool	end_sim;
	t_mutex	end_mutex;
	t_mutex	*fork;
	t_philo	*philo;
}	t_table;

int		init(t_table *table, char **av);
int		init_philo(t_table *table);
int		init_fork(t_table *table);
int		clean_up(t_table *table);
int		validate(int ac, char **av);

int		run_simulation(t_table *table);
void	*monitor(void *data);
void	*start_routine(void *data);
void	sync_routine(t_table *table);
void	p_eat(t_philo *philo, t_table *table);
void	p_sleep(t_philo *philo, t_table *table);
void	p_think(t_philo *philo, t_table *table);
void	p_die(t_philo *philo, t_table *table);

int		is_end_sim(t_table *table);

void	log_activity(long start_time, int id, char *msg);
void	usleep_ms(long ms);
long	get_time_ms(void);
int		ft_atoi(const char *str);

#endif
