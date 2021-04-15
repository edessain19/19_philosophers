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

#include "../include/philo_two.h"

int	thinking(t_data *two, int i)
{
	char		*mess;

	mess = ft_strdup(" is thinking\n");
	if (two->status == -1)
		print_str(two, i + 1, mess);
	return (0);
}

int	sleeping(t_data *two, int i)
{
	char		*mess;

	mess = ft_strdup(" is sleeping\n");
	if (two->status == -1)
	{
		print_str(two, i + 1, mess);
		ft_sleep(two, two->time_to_sleep);
	}
	return (0);
}

int	eating(t_data *two, int i)
{
	if (two->status == -1)
	{
		print_str_eat(two, i + 1);
		two->last_eat[i] = get_time(two);
		ft_sleep(two, two->time_to_eat);
	}
	return (0);
}

void	*routine_time(void *arg)
{
	t_data		*two;
	int			i;

	two = get_struct();
	while (two->status == -1)
	{
		i = -1;
		while (++i < two->nbr_of_philo)
		{
			if ((get_time(two) - two->last_eat[i]) > two->time_to_die)
			{
				two->status = 1;
				print_str_dead(two, i + 1, get_time(two));
				return (0);
			}
		}
		if (check_count_eat() > 0)
		{
			sem_wait(two->sem_global);
			two->status = 1;
			sem_post(two->sem_dead);
		}
		usleep(4000);
	}
	return (arg);
}

void	*routine(void *arg)
{
	t_data		*two;
	int			i;

	two = get_struct();
	i = *(int *)arg;
	two->last_eat[i] = get_time(two);
	while (two->status == -1)
	{
		thinking(two, i);
		sem_wait(two->sem_forks);
		print_str(two, i + 1, ft_strdup(" has taken a fork\n"));
		sem_wait(two->sem_forks);
		eating(two, i);
		sem_post(two->sem_forks);
		sem_post(two->sem_forks);
		sleeping(two, i);
	}
	return (0);
}
