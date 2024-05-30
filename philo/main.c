/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:33:52 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/30 08:57:52 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	printf("-10: %ld\n", ft_atoi("-10"));
	printf("-1: %ld\n", ft_atoi("-1"));
	printf("0: %ld\n", ft_atoi("0"));
	printf("1: %ld\n", ft_atoi("1"));
	printf("10: %ld\n", ft_atoi("10"));
	printf("100: %ld\n", ft_atoi("100"));
	printf("1234: %ld\n", ft_atoi("1234"));
	printf("12345: %ld\n", ft_atoi("12345"));
	printf("-2147483648: %ld\n", ft_atoi("-2147483648"));
	printf("2147483647: %ld\n", ft_atoi("2147483647"));
}
