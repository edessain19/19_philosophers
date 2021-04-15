/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by edessain          #+#    #+#             */
/*   Updated: 2021/03/02 15:02:28 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo_two.h"

int	init_thread_and_sem(t_data *two)
{
	two->thread = malloc(sizeof(pthread_t) * two->nbr_of_philo);
	memset(two->thread, 0, two->nbr_of_philo * 8);
	sem_unlink("sem_forks");
	sem_unlink("sem_global");
	sem_unlink("sem_dead");
	two->sem_dead = sem_open("sem_dead", O_CREAT, 0660, 1);
	if (two->sem_dead == SEM_FAILED)
		return (1);
	two->sem_forks = sem_open("sem_forks", O_CREAT, 0660,
			two->nbr_of_philo);
	if (two->sem_forks == SEM_FAILED)
		return (1);
	two->sem_global = sem_open("sem_global", O_CREAT, 0660, 1);
	if (two->sem_global == SEM_FAILED)
		return (1);
	sem_wait(two->sem_dead);
	return (0);
}

int	philo_in_action(t_data *two)
{
	int	i;
	int	*status;

	status = NULL;
	if (init_thread_and_sem(two))
		return (0);
	i = -1;
	while (++i < two->nbr_of_philo)
		pthread_create(&two->thread[i], NULL, &routine, &two->iter[i]);
	pthread_create(&two->thread_time, NULL, &routine_time, NULL);
	sem_wait(two->sem_dead);
	return (0);
}

t_data	*get_struct(void)
{
	static t_data	two;

	return (&two);
}

int	main(int argc, char **argv)
{
	t_data	*two;
	int		i;

	i = 0;
	two = get_struct();
	if (error_arg(argc, argv))
		return (0);
	if (init_struct(two))
		return (0);
	if (parse_values(two, argc, argv))
		return (0);
	if (complete_values(two))
		return (0);
	two->t_start = get_time(two);
	philo_in_action(two);
	free_all(two);
	return (0);
}
