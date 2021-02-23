/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:47:32 by edessain          #+#    #+#             */
/*   Updated: 2021/02/19 12:55:48 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./include/philo_one.h"

int creat_thread(t_data *one)
{
    int         i;
    int         *statut;

    i = 0;
    statut = NULL;
    pthread_mutex_init(&one->global, NULL);
    pthread_mutex_init(&one->dead, NULL);
    pthread_mutex_lock(&one->dead);
    while (i < one->number_of_philo)
    {
        pthread_mutex_init(&one->mutex[i], NULL);
        one->name[i] = i;
        one->last_eat[i] = 0;
        i++;
    }
    i = 0;
    while (i < one->number_of_philo)
    {
        pthread_create(&one->philo[i], NULL, &routine, &one->name[i]);
        i++;
    }
	pthread_create(&one->check_dead, NULL, &check_time, NULL);
    pthread_mutex_lock(&one->dead);
    destroy_mutex(one);
	ft_free(one);
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
