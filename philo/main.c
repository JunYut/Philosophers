/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:33:52 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/29 17:58:59 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	printf("%ld\n", ft_atoi("-2147483648"));
	printf("%ld\n", ft_atoi("2147483647"));
	printf("%ld\n", ft_atoi("-10"));
	printf("%ld\n", ft_atoi("-1"));
	printf("%ld\n", ft_atoi("0"));
	printf("%ld\n", ft_atoi("1"));
	printf("%ld\n", ft_atoi("10"));
	printf("%ld\n", ft_atoi("100"));
	printf("%ld\n", ft_atoi("1000"));
	printf("%ld\n", ft_atoi("10000"));
}
