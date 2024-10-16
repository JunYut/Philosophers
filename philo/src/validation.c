/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:38:42 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/10/16 13:06:45 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_num(char *str);

int	validate(int ac, char **av)
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
		if (!is_num(av[i]))
		{
			printf("Error: arguments must be positive integers\n");
			return (0);
		}
		if (ft_atoi(av[i]) < 0)
		{
			printf("Error: value too large\n");
			return (0);
		}
	}
	return (1);
}

static int	is_num(char *str)
{
	int	i;

	if (str[0] == '\0')
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}
