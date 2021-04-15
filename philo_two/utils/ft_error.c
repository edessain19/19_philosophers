/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by edessain          #+#    #+#             */
/*   Updated: 2021/03/02 15:02:28 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

int	error_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5)
	{
		write(2, "Not enough arguments\n", 21);
		return (1);
	}
	else if (argc > 6)
	{
		write(2, "Too many arguments\n", 19);
		return (1);
	}
	while (i < argc)
	{
		if (!only_digit(argv[i]))
		{
			write(2, "Invalid argument\n", 18);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_struct(t_data *two)
{
	two->nbr_of_philo = 0;
	two->time_to_die = 0;
	two->time_to_eat = 0;
	two->time_to_sleep = 0;
	two->nbr_of_time_each_philo_must_eat = 0;
	two->t_start = 0;
	two->status = -1;
	return (0);
}

int	free_all(t_data *two)
{
	free(two->count_eat);
	free(two->has_eat);
	free(two->iter);
	free(two->last_eat);
	free(two->thread);
	return (0);
}
