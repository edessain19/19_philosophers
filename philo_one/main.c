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

#include "./include/philo_one.h"

void 	init_thread(t_data *one)
{
	int			i;

	i = 0;
	pthread_mutex_init(&one->global, NULL);
	pthread_mutex_init(&one->dead, NULL);
	pthread_mutex_lock(&one->dead);
	while (i < one->number_of_philo)
	{
		pthread_mutex_init(&one->mutex[i], NULL);
		one->name[i] = i;
		one->last_eat[i] = 0;
		one->iter[i] = 0;
		i++;
	}

}

int		creat_thread(t_data *one)
{
	int			i;

	i = 0;
	init_thread(one);
	while (i < one->number_of_philo)
	{
		pthread_create(&one->philo[i], NULL, &routine, &one->name[i]);
		i++;
	}
	pthread_create(&one->check_dead, NULL, &check_time, NULL);
	// pthread_join(one->check_dead, NULL);
	// i = 0;
	// while (i < one->number_of_philo)
	// {
	// 	pthread_join(one->philo[i], (void *)&one->name[i]);
	// 	i++;
	// }
	pthread_mutex_lock(&one->dead);
	destroy_mutex(one);
	return (1);
}

int		main(int argc, char **argv)
{
	t_data		one;

	init_struct(&one);
	if (fill_struct(&one, argc, argv))
		return (-1);
	*static_struct() = &one;
	creat_thread(&one);
	ft_free(&one);
	return (0);
}
