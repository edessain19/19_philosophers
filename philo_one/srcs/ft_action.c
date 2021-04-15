/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:04:21 by edessain          #+#    #+#             */
/*   Updated: 2021/02/25 13:39:06 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void	eating(t_data *one, int i, int fork, int next_fork)
{
	long int	time;

	pthread_mutex_lock(&one->mutex[fork]);
	ft_print_fork(get_time(one), i + 1);
	pthread_mutex_lock(&one->mutex[next_fork]);
	time = get_time(one);
	if (one->statut == -1)
	{
		ft_print_eat(get_time(one), i + 1);
		one->last_eat[i] = time;
	}
	ft_sleep(one, one->time_to_eat);
	pthread_mutex_unlock(&one->mutex[fork]);
	pthread_mutex_unlock(&one->mutex[next_fork]);
}

void	sleeping(t_data *one, int i)
{
	long int	time;

	time = get_time(one);
	if (one->statut == -1)
	{
		ft_print_str(time, i + 1, ft_strdup(" is sleeping\n"));
		ft_sleep(one, one->time_to_sleep);
	}
}

void	*check_time(void *arg)
{
	long int		time;
	int				nb;
	t_data			*one;

	one = *static_struct();
	nb = 0;
	pthread_detach(one->check_dead);
	while (one->statut == -1)
	{
		while (nb < one->number_of_philo)
		{
			time = get_time(one);
			if (one->time_to_die < time - one->last_eat[nb])
			{
				one->statut = nb;
				ft_print_dead(time, one->statut + 1);
				return (NULL);
			}
			nb++;
		}
		if (one->number_of_time != -1 && one->nb_of_meals >= one->nb_of_meals_max)
		{
			pthread_mutex_lock(&one->global);
			one->statut = nb;
			pthread_mutex_unlock(&one->dead);
			return (NULL);
		}
		nb = 0;
		usleep(3600);
	}
	return (arg);
}

void	*routine(void *arg)
{
	int				i;
	int				fork_right;
	int				fork_left;
	t_data			*one;

	one = *static_struct();
	i = *(int *)arg;
	fork_left = i;
	fork_right = (i + 1) % one->number_of_philo;
	if (i % 2 == 0)
	{
		fork_left = (i + 1) % one->number_of_philo;
		fork_right = i;
	}
	one->last_eat[i] = get_time(one);
	pthread_detach(*one->philo);
	while (one->statut == -1)
	{
		if (one->statut == -1)
			ft_print_str(get_time(one), i + 1, ft_strdup(" is thinking\n"));
		eating(one, i, fork_left, fork_right);
		sleeping(one, i);
	}
	return (NULL);
}
