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
//	printf("philo[%i] a mamge à %li ms\n", i, time);
	usleep(one->time_to_eat * 1000);
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
				printf("%li %i died\n", time, one->statut + 1);
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
	int 			nb;
    int         	fork_next;
    t_data       	*one;

	one = *static_struct();
	i = *(int *)arg;
	
	if (i % 2 == 0)
	{
    	nb = i;
		fork_next = (i + 1) % one->number_of_philo;
	}
	 else
 	{
 		nb = (i + 1) % one->number_of_philo;
 	 	fork_next = i;
 	 }
	one->last_eat[i] = get_time() - one->time_start;
	printf("philo[%i] a mamge à %li ms\n", i, one->last_eat[i]);
	while (one->statut == -1)
	{
		if (one->statut == -1)
			printf("%li %i is thinking\n", get_time() - one->time_start, i + 1);
		pthread_mutex_lock(&one->mutex[nb]);
		if (one->statut == -1)
			printf("%li %i has taken a fork\n", get_time() - one->time_start, i + 1);
		pthread_mutex_lock(&one->mutex[fork_next]);
		if (one->statut == -1)
			printf("%li %i is eating\n", get_time() - one->time_start, i + 1);
		eating(one, i);
		pthread_mutex_unlock(&one->mutex[nb]);
		pthread_mutex_unlock(&one->mutex[fork_next]);
		if (one->statut == -1)
			printf("%li %i is sleeping\n", get_time() - one->time_start, i + 1);
		usleep(one->time_to_sleep * 1000);
	}
	return (NULL);
}
