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

void    ft_print_str(long int time, int philo, char *message)
{
    char    *dest;
    char    *time_philo;
    char    *nb_philo;

    time_philo = ft_itoa((int)time);
    nb_philo = ft_itoa(philo);
    dest = ft_strjoin(time_philo, " ");
    dest = ft_strjoin(dest, nb_philo);
    dest = ft_strjoin(dest, " ");
    dest = ft_strjoin(dest, message);
    write(1, dest, ft_strlen(dest));
    free(dest);
    free(time_philo);
    free(nb_philo);
}

void    lock_mutex(t_data *one, int philo)
{
    int i;

    i = 0;
    while (i < one->number_of_philo)
    {
        if (i != philo)
        {
            pthread_mutex_unlock(&one->mutex[i]);
            pthread_mutex_lock(&one->mutex[i]); 
        }
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
    }
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