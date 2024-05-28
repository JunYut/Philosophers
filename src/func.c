# include "philosophers.h"

void *func1(void *arg)
{
	vars	*v = (vars *)arg;

	// pthread_mutex_lock(&v->mutex);
	printf("Start func1\n");
	v->content = 1;
	printf("End func1\n\n");
	// pthread_mutex_unlock(&v->mutex);

	return (NULL);
}

void *func2(void *arg)
{
	vars	*v = (vars *)arg;

	// pthread_mutex_lock(&v->mutex);
	printf("Start func2\n");
	v->content = 2;
	printf("End func2\n\n");
	// pthread_mutex_unlock(&v->mutex);

	return (NULL);
}

void *func3(void *arg)
{
	vars	*v = (vars *)arg;

	// pthread_mutex_lock(&v->mutex);
	printf("Start func3\n");
	v->content = 3;
	printf("End func3\n\n");
	// pthread_mutex_unlock(&v->mutex);

	return (NULL);
}

void *func4(void *arg)
{
	vars	*v = (vars *)arg;

	// pthread_mutex_lock(&v->mutex);
	printf("Start func4\n");
	v->content = 4;
	printf("End func4\n\n");
	// pthread_mutex_unlock(&v->mutex);

	return (NULL);
}

void *func5(void *arg)
{
	vars	*v = (vars *)arg;

	// pthread_mutex_lock(&v->mutex);
	printf("Start func5\n");
	v->content = 5;
	printf("End func5\n\n");
	// pthread_mutex_unlock(&v->mutex);

	return (NULL);
}
