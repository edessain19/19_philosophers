/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:04:21 by edessain          #+#    #+#             */
/*   Updated: 2021/02/18 13:09:39 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void sleeping(void)
{

}

void eating(void)
{

}

void thinking(void)
{

}

void *routine(void *arg)
{
    int         i;
    int         fork_next;
    t_data       *one;

    one = *static_struct();
    i = *(int *)arg;
    printf("philo number : %i\n", i);

    fork_next = (i + 1) % one->number_of_philo;
    pthread_mutex_lock(one->mutex(i)));
    pthread_mutex_lock(one->mutex(fork_next));
    printf("|philo[%i] commence à manger|\n", i);
    pthread_mutex_unlock(one->mutex(i));
    pthread_mutex_unlock(one->mutex(i));
//    usleep(one->time_to_eat);
    return (NULL);
}
