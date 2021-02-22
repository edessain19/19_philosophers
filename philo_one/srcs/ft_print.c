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

    time_philo = ft_itoa((int)time);
    nb_philo = ft_itoa(philo);
    dest = ft_strjoin(time_philo, " ");
    dest = ft_strjoin_free(dest, nb_philo);
    dest = ft_strjoin_free(dest, " ");
    dest = ft_strjoin_free(dest, message);
    write(1, dest, ft_strlen(dest));
    free(dest);
    free(time_philo);
    free(nb_philo);
}

void    ft_print_dead(long int time, int philo)
{
    char    *dest;
    char    *time_philo;
    char    *nb_philo;

    time_philo = ft_itoa((int)time);
    nb_philo = ft_itoa(philo);
    dest = ft_strjoin(time_philo, " ");
    dest = ft_strjoin_free(dest, nb_philo);
    dest = ft_strjoin_free(dest, " ");
    dest = ft_strjoin_free(dest, "died\n");
    usleep(100);
    write(1, dest, ft_strlen(dest));
    free(dest);
    free(time_philo);
    free(nb_philo);
}