/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:47:32 by edessain          #+#    #+#             */
/*   Updated: 2021/02/18 13:02:30 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./include/philo_one.h"

int creat_thread(t_data *one)
{
    int         i;
    int         *statut;

    i = 0;
    statut = NULL;
    while (i < one->number_of_philo)
    {
        one->name[i] = i;
        one->philo[i] = malloc(sizeof(pthread_t));
        one->mutex[i] = malloc(sizeof(pthread_mutex_t));
        pthread_create(one->philo[i], NULL, &routine, &one->name[i]);
        pthread_join(*one->philo[i], (void *)&statut);
        pthread_mutex_init(one->mutex[i], NULL);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_data       one;

    init_struct(&one);
    fill_struct(&one, argc, argv);
    *static_struct() = &one;
    creat_thread(&one);
    return (0);
}
