/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:38:42 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/15 13:53:53 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_digit(char *str);

int	validation(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (0);
	}
	i = 0;
	while (++i < ac)
	{
		if (is_digit(av[i]) == -1)
		{
			printf("Error: arguments must be positive integers\n");
			return (0);
		}
	}
}

static int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}
