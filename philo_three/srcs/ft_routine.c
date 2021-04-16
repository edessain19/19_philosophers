/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by edessain          #+#    #+#             */
/*   Updated: 2021/02/26 11:35:53 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

void	*routine_time(void *arg)
{
	t_data	*three;

	three = get_struct();
	while (three->status == -1)
	{
		if ((get_time(three) - three->last_eat) > three->time_to_die)
		{
			three->status = 1;
			print_str_dead(three, three->philo, (get_time(three)));
			return (0);
		}
		usleep(4000);
	}
	return (arg);
}

int	thinking(t_data *three)
{
	char		*mess;

	mess = ft_strdup(" is thinking\n");
	if (three->status == -1)
		print_str(three, three->philo, mess);
	return (0);
}

int	sleeping(t_data *three)
{
	char		*mess;

	mess = ft_strdup(" is sleeping\n");
	if (three->status == -1)
	{
		print_str(three, three->philo, mess);
		ft_sleep(three, three->time_to_sleep);
	}
	return (0);
}

int	eating(t_data *three)
{
	if (three->status == -1)
	{
		three->last_eat = get_time(three);
		print_str_eat(three, three->philo);
		if (three->nbr_of_time_each_philo_must_eat > 0
			&& (three->count_eat >= three->nbr_of_time_each_philo_must_eat))
		{
			sem_post(three->sem_eat);
			three->status = 1;
		}
		ft_sleep(three, three->time_to_eat);
	}
	return (1);
}

void	routine(t_data *three)
{
	three->last_eat = get_time(three);
	while (three->status == -1)
	{
		thinking(three);
		sem_wait(three->sem_forks);
		sem_wait(three->sem_forks);
		print_str(three, three->philo, ft_strdup(" has taken a fork\n"));
		eating(three);
		sem_post(three->sem_forks);
		sem_post(three->sem_forks);
		if (three->status == 1)
			exit(0);
		sleeping(three);
	}
}
