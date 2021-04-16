/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by edessain          #+#    #+#             */
/*   Updated: 2021/02/26 11:40:59 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo_three.h"

int	init_sem(t_data *three)
{
	sem_unlink("sem_eat");
	three->sem_eat = sem_open("sem_eat", O_CREAT, 0660, three->nbr_of_philo);
	if (three->sem_eat == SEM_FAILED)
		return (1);
	sem_unlink("sem_forks");
	three->sem_forks = sem_open("sem_forks",
			O_CREAT, 0660, three->nbr_of_philo);
	if (three->sem_forks == SEM_FAILED)
		return (1);
	sem_unlink("sem_global");
	three->sem_global = sem_open("sem_global", O_CREAT, 0660, 1);
	if (three->sem_global == SEM_FAILED)
		return (1);
	return (0);
}

int	philo_in_action(t_data *three, int i)
{
	if (init_sem(three))
		return (1);
	while (++i < three->nbr_of_philo)
		sem_wait(three->sem_eat);
	i = 0;
	while (i < three->nbr_of_philo)
	{
		three->pid[i] = fork();
		three->philo = i + 1;
		if (three->pid[i] == 0)
		{
			pthread_create(&three->thread_time, NULL, &routine_time, NULL);
			routine(three);
		}
		i++;
	}
	i = -1;
	while (++i < three->nbr_of_philo)
		sem_wait(three->sem_eat);
	i = -1;
	while (++i < three->nbr_of_philo)
		kill(three->pid[i], SIGKILL);
	return (0);
}

t_data	*get_struct(void)
{
	static t_data	three;

	return (&three);
}

int	main(int argc, char **argv)
{
	t_data	*three;
	int		i;

	i = 0;
	three = get_struct();
	if (error_arg(argc, argv))
		return (0);
	if (init_struct(three))
		return (0);
	if (parse_values(three, argc, argv))
		return (0);
	if (complete_values(three))
		return (0);
	three->t_start = get_time(three);
	if (philo_in_action(three, -1))
		return (0);
	free_all(three);
	return (0);
}
