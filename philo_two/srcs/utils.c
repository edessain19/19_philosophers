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

void	ft_sleep(t_data *two, int time)
{
	int			i;
	long int	time_now;

	time_now = get_time(two);
	i = 0;
	while (i < 10 * time)
	{
		i++;
		if (get_time(two) - time_now >= time)
			break ;
		usleep(100);
	}
}

long	get_time(t_data *two)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds - two->t_start);
}

int	only_digit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	check_count_eat(void)
{
	int		i;
	t_data	*two;

	two = get_struct();
	i = 0;
	while (i < two->nbr_of_philo)
	{
		if (two->count_eat[i] == two->nbr_of_time_each_philo_must_eat)
			two->has_eat[i] = 1;
		i++;
	}
	i = 0;
	while (i < two->nbr_of_philo)
	{
		if (two->has_eat[i] == 0)
			return (-1);
		i++;
	}
	if (two->nbr_of_time_each_philo_must_eat > 0)
		return (1);
	return (0);
}
