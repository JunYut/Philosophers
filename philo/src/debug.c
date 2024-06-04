/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:03:07 by we                #+#    #+#             */
/*   Updated: 2024/06/04 08:46:35 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_forks(int *forks, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		printf("forks[%p]: %d\n", (void *)(forks + i), forks[i]);
	printf("\n");

}

void	print_id(t_philo *philos, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		printf("id: %d\n", philos[i].id);
	printf("\n");
}

void	debug(char *msg)
{
	static int	i;

	if (msg)
		printf("debug[%d]: %s\n", i++, msg);
	else
		printf("debug[%d]\n", i++);
}
