/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:03:07 by we                #+#    #+#             */
/*   Updated: 2024/06/03 11:56:35 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_forks(char *forks, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		printf("forks[%d]: %d\n", i, forks[i]);
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
