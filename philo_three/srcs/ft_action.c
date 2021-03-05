/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:04:21 by edessain          #+#    #+#             */
/*   Updated: 2021/02/25 13:39:06 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

void	eating(t_data *three, int i)
{
	long int	time;

	time = get_time(three);
	three->last_eat = time;
    three->nb_of_meals--;
    if (three->nb_of_meals == 0)
    {
        sem_post(three->eat);
        three->statut = 1;
    }
    ft_print_str(time, i + 1, ft_strdup(" is eating\n"));
	ft_sleep(three, three->time_to_eat);
}

void	sleeping(t_data *three, int i)
{
	long int	time;

	time = get_time(three);
	if (three->statut == -1)
	{
		ft_print_str(time, i + 1, ft_strdup(" is sleeping\n"));
		ft_sleep(three, three->time_to_sleep);
	}
}

void	*check_time(void *arg)
{
	t_data			*three;
	long int		time;
	int				i;

	three = *static_struct();
	i = *(int *)arg;

	pthread_detach(three->check_dead);
	while (three->statut == -1)
	{
		time = get_time(three);
        if (three->time_to_die < time - three->last_eat)
		{
			three->statut = i;
			ft_print_dead(time, three->statut + 1);
			return (NULL);
		}
		usleep(4000);
	}
	return (NULL);
}

int 	*routine(t_data *three, int i)
{
	three->last_eat = get_time(three);
	while (three->statut == -1)
	{
		if (three->statut == -1)
			ft_print_think(get_time(three), i + 1);
		sem_wait(three->fork);
		sem_wait(three->fork);
		if (three->statut == -1)
			ft_print_fork(get_time(three), i + 1);
		eating(three, i);
		sem_post(three->fork);
		sem_post(three->fork);
		if (three->statut != -1)
			return (0);
		sleeping(three, i);
	}
	return (0);
}