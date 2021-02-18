/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:29:15 by edessain          #+#    #+#             */
/*   Updated: 2021/02/18 13:06:16 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

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
    one->philo = malloc(sizeof(pthread_t *));
    one->mutex = malloc(sizeof(pthread_mutex_t *));
    one->name = malloc(sizeof(int) * one->number_of_philo);
    one->number_of_philo = ft_atoi(argv[1]);
    one->time_to_die = ft_atoi(argv[2]);
    one->time_to_eat = ft_atoi(argv[3]);
    one->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        one->number_of_time = ft_atoi(argv[5]);
    else
        one->number_of_time = 1;
    return (0);
}
