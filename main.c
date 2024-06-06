# include "philosophers.h"

int main(void)
{
	pthread_t	thread[5];
	void		*(*func[5])(void *) = {func1, func2, func3, func4, func5};
	vars		arg;

	pthread_mutex_init(&arg.mutex, NULL);
	for (int i = 0; i < 5; i++)
	{
		pthread_create(&thread[i], NULL, func[i], &arg);
	}
	for (int i = 0; i < 5; i++)
		pthread_join(thread[i], NULL);
	pthread_mutex_destroy(&arg.mutex);

	// printf("data: %d\n", arg.content);

	return (0);
}
