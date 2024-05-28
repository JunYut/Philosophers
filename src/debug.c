# include "philosophers.h"

void	debug(const char *str)
{
	static int	i;

	if (str)
		printf("debug[%d]: %s\n", i++, str);
	else
		printf("debug[%d]\n", i);
}
