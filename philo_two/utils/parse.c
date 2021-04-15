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

int	complete_values2(t_data *two)
{
	int	i;

	i = -1;
	two->has_eat = (int *)malloc(sizeof(int) * two->nbr_of_philo);
	if (!two->has_eat)
		return (1);
	while (++i < two->nbr_of_philo)
		two->has_eat[i] = 0;
	i = -1;
	two->last_eat = (long int *)malloc(sizeof(long int)
			* two->nbr_of_philo);
	if (!two->last_eat)
		return (1);
	while (++i < two->nbr_of_philo)
		two->last_eat[i] = 0;
	return (0);
}

int	complete_values(t_data *two)
{
	int	i;

	two->iter = (int *)malloc(sizeof(int) * two->nbr_of_philo);
	if (!two->iter)
		return (1);
	i = -1;
	while (++i < two->nbr_of_philo)
		two->iter[i] = i;
	i = -1;
	two->count_eat = (int *)malloc(sizeof(int) * two->nbr_of_philo);
	if (!two->count_eat)
		return (1);
	while (++i < two->nbr_of_philo)
		two->count_eat[i] = 0;
	return (complete_two2(two));
}

int	parse_values(t_data *two, int argc, char **argv)
{
	two->nbr_of_philo = ft_atoi(argv[1]);
	two->time_to_die = ft_atoi(argv[2]);
	two->time_to_eat = ft_atoi(argv[3]);
	two->time_to_sleep = ft_atoi(argv[4]);
	if (two->nbr_of_philo < 2)
		return (1);
	if (two->time_to_die < 0)
		return (1);
	if (two->time_to_eat < 0)
		return (1);
	if (two->time_to_sleep < 0)
		return (1);
	if (argc == 6)
		two->nbr_of_time_each_philo_must_eat = ft_atoi(argv[5]);
	else
		two->nbr_of_time_each_philo_must_eat = 0;
	return (0);
}
