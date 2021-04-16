/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 09:16:31 by edessain          #+#    #+#             */
/*   Updated: 2021/02/26 11:18:13 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

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

int	init_struct(t_data *three)
{
	three->nbr_of_philo = 0;
	three->time_to_die = 0;
	three->time_to_eat = 0;
	three->time_to_sleep = 0;
	three->nbr_of_time_each_philo_must_eat = 0;
	three->t_start = 0;
	three->status = -1;
	three->last_eat = 0;
	three->philo = 0;
	three->count_eat = 0;
	return (0);
}

int	free_all(t_data *three)
{
	free(three->has_eat);
	return (0);
}
