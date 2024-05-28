# include "philosophers.h"

int main(void)
{
	pthread_t	thread[5];
	void		*(*func[5])(void *) = {func1, func2, func3, func4, func5};
	int			data = 0;

	for (int i = 0; i < 5; i++)
		pthread_create(&thread[i], NULL, func[i], &data);
	for (int i = 0; i < 5; i++)
		pthread_join(thread[i], NULL);
	printf("data: %d\n", data);

	return (0);
}
