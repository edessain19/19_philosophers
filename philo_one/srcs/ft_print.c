/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:14:32 by edessain          #+#    #+#             */
/*   Updated: 2021/02/18 18:28:48 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void    ft_print_str(long int time, int philo, char *message)
{
    char    *dest;
    char    *time_philo;
    char    *nb_philo;
    t_data  *one;

    one = *static_struct();
    time_philo = ft_itoa((int)time);
    nb_philo = ft_itoa(philo);
    dest = ft_strjoin(time_philo, " ");
    dest = ft_strjoin_free(ft_strdup(dest), nb_philo);
    dest = ft_strjoin_free_all(ft_strdup(dest), message);
    pthread_mutex_lock(&one->global);	
    write(1, dest, ft_strlen(dest));
    free(dest);
    free(nb_philo);
    free(time_philo);
    pthread_mutex_unlock(&one->global);
}

void    ft_print_fork(long int time, int philo)
{
    char    *dest;
    char    *time_philo;
    char    *nb_philo;
    char    *msg;
    t_data  *one;

    one = *static_struct();
    msg = ft_strdup(" has taken a fork\n");
    time_philo = ft_itoa((int)time);
    nb_philo = ft_itoa(philo);
    dest = ft_strjoin(time_philo, " ");
    dest = ft_strjoin_free(ft_strdup(dest), nb_philo);
    dest = ft_strjoin_free_all(ft_strdup(dest), msg);
    pthread_mutex_lock(&one->global);	
    write(1, dest, ft_strlen(dest));
    free(dest);    
    free(nb_philo);
    free(time_philo);
    pthread_mutex_unlock(&one->global);
}

void    ft_print_think(long int time, int philo)
{
    char    *dest;
    char    *time_philo;
    char    *nb_philo;
    char    *msg;
    t_data  *one;

    one = *static_struct();
    msg = ft_strdup(" is thinking\n");
    time_philo = ft_itoa((int)time);
    nb_philo = ft_itoa(philo);
    dest = ft_strjoin(time_philo, " ");
    dest = ft_strjoin_free(ft_strdup(dest), nb_philo);
    dest = ft_strjoin_free_all(ft_strdup(dest), msg);
    pthread_mutex_lock(&one->global);	
    write(1, dest, ft_strlen(dest));
    free(dest);
    free(nb_philo);
    free(time_philo);
    pthread_mutex_unlock(&one->global);
}

void    ft_print_dead(long int time, int philo)
{
    char    *dest;
    char    *time_philo;
    char    *nb_philo;
    char    *msg;
    t_data  *one;

    one = *static_struct();
    msg = ft_strdup(" died\n");
    time_philo = ft_itoa((int)time);
    nb_philo = ft_itoa(philo);
    dest = ft_strjoin(time_philo, " ");
    dest = ft_strjoin_free(ft_strdup(dest), nb_philo);
    dest = ft_strjoin_free_all(ft_strdup(dest), msg);
    pthread_mutex_lock(&one->global);	
    write(1, dest, ft_strlen(dest));
    free(dest);
    free(nb_philo);
    free(time_philo);
    pthread_mutex_unlock(&one->dead);
}