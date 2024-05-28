# pragma once

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct vars
{
	pthread_mutex_t	mutex;
	int				content;
}				vars;

void	*func1(void *arg);
void	*func2(void *arg);
void	*func3(void *arg);
void	*func4(void *arg);
void	*func5(void *arg);

void	debug(const char *str);
