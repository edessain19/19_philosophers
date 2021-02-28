/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:47:32 by edessain          #+#    #+#             */
/*   Updated: 2021/02/25 13:29:07 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo_two.h"

int		creat_thread(t_data *two)
{
	int			i;

	i = 0;
	 sem_unlink(&two->fork);
	while (i < two->number_of_philo)
	{
		two->name[i] = i;
		two->last_eat[i] = 0;
		two->iter[i] = 0;
		pthread_create(&two->philo[i], NULL, &routine, &two->name[i]);
		i++;
	}
	pthread_create(&two->check_dead, NULL, &check_time, NULL);
	while (i < two->number_of_philo)
	{
		pthread_join(two->philo[i], NULL);
		i++;
	}
	destroy_sem(two);
	return (1);
}

int		main(int argc, char **argv)
{
	t_data		two;

	init_struct(&two);
	fill_struct(&two, argc, argv);
	*static_struct() = &two;
	creat_thread(&two);
	return (0);
}
