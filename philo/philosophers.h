/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:33:55 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/06/07 16:44:07 by we               ###   ########.fr       */
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

# define GREEN "\033[1;32m"
# define RESET "\033[0m"

enum e_state
{
	DEAD = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3
};


// Don't need to free 'left_fork' and 'right_fork'
typedef struct s_philo
{
	pthread_mutex_t	state_mutex;
	int				id;
	char			state;
	int				*left_fork;
	int				*right_fork;
	long			current_time;
	long			last_eat_time;
	long			starve_time;
	int				eat_count;
}	t_philo;

typedef struct s_table
{
	t_philo	*philos;
	int		*forks;
	long	start_time;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat_count;
	int		total_eat_count;
	int		philo_count;
	int		init_count;
}	t_table;

void	start_simulation(t_table *table);
void	*philo_routine(void *arg);
void	*timer(void *arg);
void	p_eat(t_philo *p, t_table *t);
void	p_take_fork(t_philo *p, long start);
void	p_sleep(t_philo *p, t_table *t);
void	p_think(t_philo *p, long start);
void	p_die(t_philo *p, long start, int *p_count, pthread_mutex_t *m);

void	init_env(t_table *t, char *argv[]);
t_philo	*init_philos(int *forks, int count, long starve_time);
int		*init_forks(int count);
void	clean_up(t_table *table);

char	validation(char *argv[]);
char	is_num(char *str);

void	log_activity(long start_time, int id, char *msg);
long	get_time_ms(void);
void	*ft_malloc(size_t size);
long	ft_atoi(const char *str);
int		ft_strlen(const char *str);

void	print_forks(int *forks, int count, char a_or_i);
void	print_id(t_philo *philos, int count);
void	debug(char *msg);

#endif
