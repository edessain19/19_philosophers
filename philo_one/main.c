/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by edessain          #+#    #+#             */
/*   Updated: 2021/03/02 14:51:20 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/philo_one.h"

int	check_count_eat(void)
{
	int		i;
	t_data	*one;

	one = get_struct();
	i = 0;
	while (i < one->nbr_of_philo)
	{
		if (one->count_eat[i] == one->nbr_of_time_each_philo_must_eat)
			one->has_eat[i] = 1;
		i++;
	}
	i = 0;
	while (i < one->nbr_of_philo)
	{
		if (one->has_eat[i] == 0)
			return (-1);
		i++;
	}
	if (one->nbr_of_time_each_philo_must_eat > 0)
		return (1);
	return (0);
}

int	destroy_mutex(t_data *one)
{
	int		i;

	i = 0;
	while (i < one->nbr_of_philo)
	{
		pthread_mutex_destroy(&one->mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&one->global_mutex);
	pthread_mutex_destroy(&one->dead_mutex);
	return (0);
}

int	init_and_malloc_mutex_and_thread(t_data *one)
{
	int	i;

	one->mutex = malloc(sizeof(pthread_mutex_t) * one->nbr_of_philo);
	memset(one->mutex, 0, one->nbr_of_philo * 8);
	one->thread = malloc(sizeof(pthread_t) * one->nbr_of_philo);
	memset(one->thread, 0, one->nbr_of_philo * 8);
	pthread_mutex_init(&one->global_mutex, NULL);
	pthread_mutex_init(&one->dead_mutex, NULL);
	pthread_mutex_lock(&one->dead_mutex);
	i = -1;
	while (++i < one->nbr_of_philo)
		pthread_mutex_init(&one->mutex[i], NULL);
	return (0);
}

int	philo_in_action(t_data *one)
{
	int	i;
	int	*status;

	status = NULL;
	init_and_malloc_mutex_and_thread(one);
	i = -1;
	while (++i < one->nbr_of_philo)
		pthread_create(&one->thread[i], NULL, &routine, &one->iter[i]);
	pthread_create(&one->thread_time, NULL, &routine_time, NULL);
	pthread_mutex_lock(&one->dead_mutex);
	destroy_mutex(one);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*one;
	int		i;

	i = 0;
	one = get_struct();
	if (error_arg(argc, argv))
		return (0);
	if (init_struct(one))
		return (0);
	if (parse_values(one, argc, argv))
		return (0);
	if (complete_values(one))
		return (0);
	one->t_start = get_time();
	philo_in_action(one);
	free_all(one);
	return (0);
}
