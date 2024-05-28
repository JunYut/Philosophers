# include "philosophers.h"

long	get_time_ms(void)
{
	struct timeval	time;
	long			ret;

	gettimeofday(&time, NULL);
	ret = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("time: %ld\n", ret);
	return (ret);
}
