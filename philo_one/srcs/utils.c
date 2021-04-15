/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by edessain          #+#    #+#             */
/*   Updated: 2021/03/02 14:51:20 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void	ft_sleep(t_data *one, int time)
{
	int			i;
	long int	time_now;

	time_now = get_time(one);
	i = 0;
	while (i < 10 * time)
	{
		i++;
		if (get_time(one) - time_now >= time)
			break ;
		usleep(100);
	}
}

long	get_time(t_data *one)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds - one->t_start);
}

int	complete_values2(t_data *one)
{
	int	i;

	i = -1;
	one->has_eat = (int *)malloc(sizeof(int) * one->nbr_of_philo);
	if (!one->has_eat)
		return (1);
	while (++i < one->nbr_of_philo)
		one->has_eat[i] = 0;
	i = -1;
	one->last_eat = (long int *)malloc(sizeof(long int)
			* one->nbr_of_philo);
	if (!one->last_eat)
		return (1);
	while (++i < one->nbr_of_philo)
		one->last_eat[i] = 0;
	return (0);
}

int	complete_values(t_data *one)
{
	int	i;

	one->iter = (int *)malloc(sizeof(int) * one->nbr_of_philo);
	if (!one->iter)
		return (1);
	i = -1;
	while (++i < one->nbr_of_philo)
		one->iter[i] = i;
	i = -1;
	one->count_eat = (int *)malloc(sizeof(int) * one->nbr_of_philo);
	if (!one->count_eat)
		return (1);
	while (++i < one->nbr_of_philo)
		one->count_eat[i] = 0;
	return (complete_values2(one));
}

int	parse_values(t_data *one, int argc, char **argv)
{
	one->nbr_of_philo = ft_atoi(argv[1]);
	one->time_to_die = ft_atoi(argv[2]);
	one->time_to_eat = ft_atoi(argv[3]);
	one->time_to_sleep = ft_atoi(argv[4]);
	if (one->nbr_of_philo < 2)
		return (1);
	if (one->time_to_die < 0)
		return (1);
	if (one->time_to_eat < 0)
		return (1);
	if (one->time_to_sleep < 0)
		return (1);
	if (argc == 6)
		one->nbr_of_time_each_philo_must_eat = ft_atoi(argv[5]);
	else
		one->nbr_of_time_each_philo_must_eat = 0;
	return (0);
}
