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

////faire fct exit ! destroy tout les mutex et free tout///

# include "./include/philo_one.h"

int creat_thread(t_data *one)
{
    int         i;
    int         *statut;
	pthread_t	check_dead;

    i = 0;
    statut = NULL;
    pthread_mutex_init(&one->global, NULL);
    while (i < one->number_of_philo)
    {
        one->name[i] = i;
        pthread_create(&one->philo[i], NULL, &routine, &one->name[i]);
        pthread_mutex_init(&one->mutex[i], NULL);
        i++;
    }
	pthread_create(&check_dead, NULL, &check_time, &one->last_eat);
  
	i = 0;
	while (i < one->number_of_philo)
	{
		pthread_join(one->philo[i], (void *)&statut);
		i++;
	}
    // destroy_mutex(one);
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
