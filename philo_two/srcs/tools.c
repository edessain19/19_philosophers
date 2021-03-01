/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:14:32 by edessain          #+#    #+#             */
/*   Updated: 2021/02/18 18:28:48 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

void	ft_sleep(t_data *two, int time)
{
	int			i;
	long int	time_now;

	time_now = get_time(two);
	i = 0;
	while (i < 10 * time)
	{
		i++;
		if (get_time(two) - time_now >= time)
			break ;
		usleep(100);
	}
}

void	destroy_sem(t_data *two)
{
    int     i;

    i = 0;
    while (i < two->number_of_philo)
    {
        sem_post(two->fork);            
        i++;
    }
    sem_close(two->fork);
    sem_close(two->global);
    sem_close(two->dead);
	ft_free(two);
}

long	get_time(t_data *two)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds - two->time_start);
}

t_data	**static_struct(void)
{
	static t_data	*two;

	return (&two);
}
