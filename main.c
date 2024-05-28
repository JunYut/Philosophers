# include "philosophers.h"

void *func1(void *arg);
void *func2(void *arg);

int main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;
	int			data;

	data = 42;
	pthread_create(&thread1, NULL, func1, &data);
	pthread_create(&thread2, NULL, func2, &data);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("data: %d\n", data);

	return (0);
}

void *func1(void *arg)
{
	printf("func1\n");
	usleep(1000);
	*(int *)arg = 100;
	return (NULL);
}

void *func2(void *arg)
{
	printf("func2\n");
	// usleep(5000);
	*(int *)arg = -100;
	return (NULL);
}
