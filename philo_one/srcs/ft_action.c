/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:04:21 by edessain          #+#    #+#             */
/*   Updated: 2021/02/18 20:05:14 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

//void thinking(t_data *one, int i)
//{


//}

void sleeping(t_data *one, int i)
{
	struct timeval temps_avant;
	struct timeval temps_apres;
	long int time;

	gettimeofday(&temps_avant, NULL);
	usleep(one->time_to_sleep);
	gettimeofday(&temps_apres, NULL);
	time = ((((temps_apres.tv_sec - temps_avant.tv_sec) * 1000000 + temps_apres.tv_usec) - temps_avant.tv_usec));
	printf("|philo[%i] a dormi pendant %li|\n", i, time);
}

void eating(t_data *one, int i)
{
	struct timeval temps_avant;
	struct timeval temps_apres;
	long int time;

	one->clock_to_die[i] = gettimeofday(&temps_avant, NULL);
	usleep(one->time_to_eat);
	gettimeofday(&temps_apres, NULL);
	time = ((((temps_apres.tv_sec - temps_avant.tv_sec) * 1000000 + temps_apres.tv_usec) - temps_avant.tv_usec));
	printf("|philo[%i] a mange pendant %li|\n", i, time);
}

void *check_time(void *arg)
{
	int 			nb;
	t_data 			*one;
	int 			dead;
	struct timeval 	temps_apres;
	long int 		time;

	one = *static_struct();
	nb = 0;
	one_is_dead = 0;
	while (dead == 0)
	{
		while (nb < one->number_of_philo)
		{
			time = gettimeofday(&temps_apres, NULL);
			if (one->time_to_die >= (time - one->clock_to_die[nb]))
				return (NULL);
			nb++;
		}
		nb = 0;
		usleep(5000);
	}
}

void *routine(void *arg)
{
    int         	i;
    int         	fork_next;
    t_data       	*one;
//	struct timeval 	temps_avant;
//	struct timeval 	temps_apres;
//	long int 		time;

	one = *static_struct();
    i = *(int *)arg;
    fork_next = (i + 1) % one->number_of_philo;
//	while (one->statut == 0 && (one->iter[i] < 0 || one->number_of_time == -1))
//	while (1)
//	{
		pthread_mutex_lock(&one->mutex[i]);
		pthread_mutex_lock(&one->mutex[fork_next]);
		eating(one, i);
		pthread_mutex_unlock(&one->mutex[i]);
		pthread_mutex_unlock(&one->mutex[fork_next]);
		sleeping(one, i);
//	}
	return (NULL);
}
