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

#include "../include/philo_one.h"

void	print_str(t_data *one, int phi, char *mess)
{
	char	*time;
	char	*philo;
	char	*str;

	pthread_mutex_lock(&one->global_mutex);
	time = ft_itoa((int)get_time(one));
	philo = ft_itoa(phi);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo);
	str = ft_strjoin_free_all(str, mess);
	write(1, str, ft_strlen(str));
	free(str);
	pthread_mutex_unlock(&one->global_mutex);
}

void	print_str_eat(t_data *one, int i)
{
	char	*philo;
	char	*time;
	char	*str;
	char	*mess;

	pthread_mutex_lock(&one->global_mutex);
	time = ft_itoa((int)(get_time(one)));
	mess = ft_strdup(" is eating\n");
	philo = ft_itoa(i);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo);
	str = ft_strjoin_free_all(str, mess);
	write(1, str, ft_strlen(str));
	one->count_eat[i - 1]++;
	free(str);
	pthread_mutex_unlock(&one->global_mutex);
}

void	print_str_dead(t_data *one, int i, long int diff)
{
	char	*philo;
	char	*time;
	char	*str;
	char	*mess;

	mess = ft_strdup(" died\n");
	philo = ft_itoa(i);
	time = ft_itoa((int)diff);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo);
	str = ft_strjoin_free_all(str, mess);
	pthread_mutex_lock(&one->global_mutex);
	write(1, str, ft_strlen(str));
	free(str);
	pthread_mutex_unlock(&one->dead_mutex);
}

int	init_struct(t_data *one)
{
	one->nbr_of_philo = 0;
	one->time_to_die = 0;
	one->time_to_eat = 0;
	one->time_to_sleep = 0;
	one->nbr_of_time_each_philo_must_eat = 0;
	one->t_start = 0;
	one->status = -1;
	return (0);
}

t_data	*get_struct(void)
{
	static t_data	one;

	return (&one);
}
