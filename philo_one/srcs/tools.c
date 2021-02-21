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

int		ft_isdigit(int c)
{
	if (c < '0' || '9' < c)
		return (0);
	return (1);
}

int    ft_atoi(const char *str)
{
    int                    i;
    int                    signe;
    unsigned long long    prev;
    unsigned long long    digit;

    i = 0;
    prev = 0;
    digit = 0;
    signe = 1;
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
        || str[i] == '\v' || str[i] == '\f')
        i++;
    if (str[i] == '-' || str[i] == '+')
        signe = (str[i++] == '-') ? -1 : 1;
    while (str[i] > 47 && str[i] < 58)
    {
        digit = digit * 10 + (str[i++] - '0');
        if (digit < prev || digit >= 9223372036854775807)
            return ((signe == -1) ? 0 : -1);
        prev = digit;
    }
    return (digit * signe);
}
