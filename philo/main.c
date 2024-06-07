/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:33:52 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/06/07 15:13:52 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	t_table	table;
	char *args[] = {0, "5", "800", "200", "200", "10"};

	init_env(&table, args);
	start_simulation(&table);
	clean_up(&table);
}
