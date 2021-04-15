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

int	thinking(t_data *one, int i)
{
	char		*mess;

	mess = ft_strdup(" is thinking\n");
	if (one->status == -1)
		print_str(one, i + 1, mess);
	return (0);
}

int	sleeping(t_data *one, int i)
{
	char		*mess;

	mess = ft_strdup(" is sleeping\n");
	if (one->status == -1)
	{
		print_str(one, i + 1, mess);
		ft_sleep(one, one->time_to_sleep);
	}
	return (0);
}

int	eating(t_data *one, int i, int fork, int next_fork)
{
	char		*mess;

	pthread_mutex_lock(&one->mutex[fork]);
	mess = ft_strdup(" has taken a fork\n");
	print_str(one, i + 1, mess);
	pthread_mutex_lock(&one->mutex[next_fork]);
	if (one->status == -1)
	{
		print_str_eat(one, i + 1);
		one->last_eat[i] = get_time(one);
		ft_sleep(one, one->time_to_eat);
	}
	pthread_mutex_unlock(&one->mutex[fork]);
	pthread_mutex_unlock(&one->mutex[next_fork]);
	return (0);
}

void	*routine_time(void *arg)
{
	t_data		*one;
	int			i;

	one = get_struct();
	while (one->status == -1)
	{
		i = -1;
		while (++i < one->nbr_of_philo)
		{
			if ((get_time(one) - one->last_eat[i]) > one->time_to_die)
			{
				one->status = 1;
				print_str_dead(one, i + 1, get_time(one));
				return (0);
			}
		}
		if (check_count_eat() > 0)
		{
			pthread_mutex_lock(&one->global_mutex);
			one->status = 1;
			pthread_mutex_unlock(&one->dead_mutex);
		}
		usleep(4000);
	}
	return (arg);
}

void	*routine(void *arg)
{
	t_data		*one;
	int			fork;
	int			next_fork;
	int			i;

	one = get_struct();
	i = *(int *)arg;
	fork = i;
	next_fork = (fork + 1) % one->nbr_of_philo;
	if (i % 2 == 0)
	{
		next_fork = i;
		fork = (next_fork + 1) % one->nbr_of_philo;
	}
	one->last_eat[i] = get_time(one);
	pthread_detach(*one->thread);
	while (one->status == -1)
	{
		thinking(one, i);
		eating(one, i, fork, next_fork);
		sleeping(one, i);
	}
	return (0);
}
