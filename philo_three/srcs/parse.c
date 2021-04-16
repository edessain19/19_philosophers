/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by edessain          #+#    #+#             */
/*   Updated: 2021/02/26 11:35:53 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

int	complete_values(t_data *three)
{
	int	i;

	i = -1;
	three->has_eat = (int *)malloc(sizeof(int) * three->nbr_of_philo);
	if (!three->has_eat)
		return (1);
	while (++i < three->nbr_of_philo)
		three->has_eat[i] = 0;
	i = -1;
	three->pid = (int *)malloc(sizeof(long int) * three->nbr_of_philo);
	if (!three->pid)
		return (1);
	while (++i < three->nbr_of_philo)
		three->pid[i] = 0;
	return (0);
}

int	parse_values(t_data *three, int argc, char **argv)
{
	three->nbr_of_philo = ft_atoi(argv[1]);
	three->time_to_die = ft_atoi(argv[2]);
	three->time_to_eat = ft_atoi(argv[3]);
	three->time_to_sleep = ft_atoi(argv[4]);
	if (three->nbr_of_philo < 2)
		return (1);
	if (three->time_to_die < 0)
		return (1);
	if (three->time_to_eat < 0)
		return (1);
	if (three->time_to_sleep < 0)
		return (1);
	if (argc == 6)
		three->nbr_of_time_each_philo_must_eat = ft_atoi(argv[5]);
	else
		three->nbr_of_time_each_philo_must_eat = 0;
	return (0);
}
