/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:14:32 by edessain          #+#    #+#             */
/*   Updated: 2021/02/18 18:28:48 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void    ft_sleep(int time)
{
    int i;
    long int time_now;

    time_now = get_time();
    i = 0;
    while (i < 10 * time)
    {
        i++;
        if (get_time() - time_now >= time)
            break;
        usleep(100);
    }
}

void    lock_mutex(t_data *one)
{
    int i;

    i = 0;
    while (i < one->number_of_philo)
    {
        pthread_mutex_lock(&one->mutex[i]); 
        i++;
    }
}

void    unlock_mutex(t_data *one)
{
    int i;

    i = 0;
    while (i < one->number_of_philo)
    {
        pthread_mutex_unlock(&one->mutex[i]); 
        i++;
    }
}

void    destroy_mutex(t_data *one)
{
    int i;

    i = 0;
    while (i < one->number_of_philo)
    {
        pthread_mutex_unlock(&one->mutex[i]); 
        pthread_mutex_destroy(&one->mutex[i]);
        i++;
    }
    pthread_mutex_destroy(&one->global);
    pthread_mutex_destroy(&one->dead);
}

long    get_time(void)
{
    struct timeval  tp;
    long            milliseconds;

    gettimeofday(&tp, NULL);
    milliseconds = tp.tv_sec * 1000;
    milliseconds += tp.tv_usec / 1000;
    return (milliseconds);
}

t_data   **static_struct(void)
{
    static t_data    *one;
    return (&one);
}