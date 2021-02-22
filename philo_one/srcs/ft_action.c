/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:04:21 by edessain          #+#    #+#             */
/*   Updated: 2021/02/19 13:02:24 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void eating(t_data *one, int i)
{
	long int time;

	time = get_time() - one->time_start;
	one->last_eat[i] = time;
	ft_sleep(one->time_to_eat);
}

void *check_time(void *arg)
{
	int 			nb;
	t_data 			*one;
	long int 		time;

	one = *static_struct();
	nb = 0;
	arg = 0;
	while (one->statut == -1)
	{
		while (nb < one->number_of_philo)
		{
			time = get_time() - one->time_start;
			if (one->time_to_die < time - one->last_eat[nb])
			{
				one->statut = nb;
				ft_print_dead(time, one->statut + 1);
				unlock_mutex(one);
				return (NULL);
			}
			nb++;
		}
		nb = 0;
		usleep(4 * 1000);
	}
	return (NULL);
}

void *routine(void *arg)
{
    int         	i;
	int 			fork_right;
    int         	fork_left;
    t_data       	*one;
	int 		iter = 0;

	one = *static_struct();
	i = *(int *)arg;	
	fork_left = i;
	fork_right = (i + 1) % one->number_of_philo;
	if (i % 2 == 0)
	{	
		fork_left = (i + 1) % one->number_of_philo;
		fork_right = i;
	 }
	one->last_eat[i] = get_time() - one->time_start;
	while (one->statut == -1)
	{
		 if (one->statut == -1)
			ft_print_str(get_time() - one->time_start, i + 1, "is thinking\n");
		pthread_mutex_lock(&one->mutex[fork_left]);	
		 if (one->statut == -1)
			ft_print_str(get_time() - one->time_start, i + 1, "has taken a fork\n");
		pthread_mutex_lock(&one->mutex[fork_right]);
		 if (one->statut == -1)
			ft_print_str(get_time() - one->time_start, i + 1, "is eating\n");
		eating(one, i);
		pthread_mutex_unlock(&one->mutex[fork_left]);
		pthread_mutex_unlock(&one->mutex[fork_right]);
		 if (one->statut == -1)
			ft_print_str(get_time() - one->time_start, i + 1, "is sleeping\n");
		ft_sleep(one->time_to_sleep);
		printf("philo = %i, tour = %i\n", i + 1, iter++);
	}
	return (NULL);
}
