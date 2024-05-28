# include "philosophers.h"

void *func1(void *arg)
{
	printf("func1\n");
	*(int *)arg = 1;
	return (NULL);
}

void *func2(void *arg)
{
	printf("func2\n");
	*(int *)arg = 2;
	return (NULL);
}

void *func3(void *arg)
{
	printf("func3\n");
	*(int *)arg = 3;
	return (NULL);
}

void *func4(void *arg)
{
	printf("func4\n");
	*(int *)arg = 4;
	return (NULL);
}

void *func5(void *arg)
{
	printf("func5\n");
	*(int *)arg = 5;
	return (NULL);
}
