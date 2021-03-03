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

#include "../include/philo_two.h"

void	eating(t_data *two, int i)
{
	long int	time;

	time = get_time(two);
	two->last_eat[i] = time;
	two->nb_of_meals--;
	if (two->statut == -1)
	{
		ft_print_str(time, i + 1, ft_strdup(" is eating\n"));
		ft_sleep(two, two->time_to_eat);
	}
}

void	sleeping(t_data *two, int i)
{
	long int	time;

	time = get_time(two);
	if (two->statut == -1)
	{
		ft_print_str(time, i + 1, ft_strdup(" is sleeping\n"));
		ft_sleep(two, two->time_to_sleep);
	}
}

int		check_iter(t_data *two, int i)
{
	if (two->nb_of_meals == 0)
	{
		two->statut = i;
        sem_wait(two->global);
		sem_post(two->dead);
		return (-1);
    }
	return (0);
}

void	*check_time(void *arg)
{
	t_data			*two;
	long int		time;
	int				nb;

	two = *static_struct();
	nb = 0;
	arg = 0;
	pthread_detach(two->check_dead);
	while (two->statut == -1)
	{
		while (nb < two->number_of_philo)
		{
			time = get_time(two);
			if (two->time_to_die < time - two->last_eat[nb])
			{
				two->statut = nb;
				ft_print_dead(time, two->statut + 1);
				return (NULL);
			}
			nb++;
		}
		nb = 0;
		usleep(4000);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	int				i;
	t_data			*two;

	two = *static_struct();
	i = *(int *)arg;
	two->last_eat[i] = get_time(two);
	pthread_detach(two->philo[i]);
	while (two->statut == -1)
	{
		if (two->number_of_time != -1 && check_iter(two, i) != 0)
			break ;
		if (two->statut == -1)
			ft_print_think(get_time(two), i + 1);
		sem_wait(two->fork);
		sem_wait(two->fork);
		if (two->statut == -1)
			ft_print_fork(get_time(two), i + 1);
		eating(two, i);
		sem_post(two->fork);
		sem_post(two->fork);
		sleeping(two, i);
	}
	return (NULL);
}