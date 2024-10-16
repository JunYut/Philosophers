/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:33:27 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/16 13:43:52 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>

# define DEBUG printf

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int			id;
	int			eat_count;
	long		starve_time;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	pthread_t	thread;
}	t_philo;

typedef struct s_table
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat_count;
	t_mutex	*fork;
	t_philo	*philo;
}	t_table;

int	init(t_table *table, char **av);
int init_philo(t_table *table);
int	init_fork(t_table *table);
int	clean_up(t_table *table);
int	validate(int ac, char **av);

void	log_activity(long start_time, int id, char *msg);
void	usleep_ms(long ms);
long	get_time_ms(void);
int	ft_atoi(const char *str);

#endif
