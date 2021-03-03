/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_the_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:29:15 by edessain          #+#    #+#             */
/*   Updated: 2021/02/19 12:54:33 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

void	ft_free(t_data *two)
{
	free(two->philo);
	free(two->name);
	free(two->last_eat);
	free(two->iter);
	two->last_eat = NULL;
	two->name = NULL;
	two->philo = NULL;
	two->iter = NULL;
}

int		check_digit(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		fill_struct(t_data *two, int argc, char **argv)
{
	if (argc < 5 || argc > 7)
		return (-1);
	if (check_digit(argc, argv) != 0)
		return (-1);
	two->number_of_philo = ft_atoi(argv[1]);
	two->time_to_die = ft_atoi(argv[2]);
	two->time_to_eat = ft_atoi(argv[3]);
	two->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		two->number_of_time = ft_atoi(argv[5]);
	else
		two->number_of_time = -1;
	two->philo = malloc(sizeof(pthread_t) * two->number_of_philo);
	two->name = malloc(sizeof(int) * two->number_of_philo);
	two->iter = malloc(sizeof(int) * two->number_of_philo);
	two->last_eat = malloc(sizeof(long) * two->number_of_philo);
	memset(two->philo, 0, two->number_of_philo * 8);
    two->nb_of_meals = two->number_of_philo * two->number_of_time;
	return (0);
}

void	init_struct(t_data *two)
{
	two->number_of_philo = 0;
	two->time_to_die = 0;
	two->time_to_eat = 0;
	two->time_to_sleep = 0;
	two->number_of_time = 0;
	two->statut = -1;
	two->time_start = 0;
	two->time_start = get_time(two);
}
