/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_the_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:29:15 by edessain          #+#    #+#             */
/*   Updated: 2021/02/19 12:54:33 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void    ft_free(t_data *one)
{
    free(one->philo);
    free(one->mutex);
    free(one->name);
    free(one->last_eat);
    free(one->iter);
    one->last_eat = NULL;
    one->name = NULL;
    one->mutex = NULL;
    one->philo = NULL;
    one->iter = NULL;
}

int     check_digit(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < argc)
    {
        while (argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]))
                return (-1);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}

int     fill_struct(t_data *one, int argc, char **argv)
{
    if (argc < 5 || argc > 7)
        return (-1);
    if (check_digit(argc, argv) != 0)
        return (-1);
	one->number_of_philo = ft_atoi(argv[1]);
    one->time_to_die = ft_atoi(argv[2]);
    one->time_to_eat = ft_atoi(argv[3]);
    one->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        one->number_of_time = ft_atoi(argv[5]);
    else
	    one->number_of_time = -1;
	one->philo = malloc(sizeof(pthread_t) * one->number_of_philo);
	one->mutex = malloc(sizeof(pthread_mutex_t) * (one->number_of_philo));
	one->name = malloc(sizeof(int) * one->number_of_philo);
    one->iter = malloc(sizeof(int) * one->number_of_philo);
	one->last_eat = malloc(sizeof(long) * one->number_of_philo);
	memset(one->philo, 0, one->number_of_philo * 8);
	memset(one->mutex, 0, one->number_of_philo * 8);
    return (0);
}

void    init_struct(t_data *one)
{
    one->number_of_philo = 0;
    one->time_to_die = 0;
    one->time_to_eat = 0;
    one->time_to_sleep = 0;
    one->number_of_time = 0;
	one->statut = -1;
    one->time_start = 0;
    one->time_start = get_time(one);
}
