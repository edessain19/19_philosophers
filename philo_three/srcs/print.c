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

void	print_str(t_data *three, int phi, char *mess)
{
	char	*time;
	char	*philo;
	char	*str;

	sem_wait(three->sem_global);
	time = ft_itoa((int)get_time(three));
	philo = ft_itoa(phi);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo);
	str = ft_strjoin_free_all(str, mess);
	write(1, str, ft_strlen(str));
	free(str);
	sem_post(three->sem_global);
}

void	print_str_eat(t_data *three, int i)
{
	char	*philo;
	char	*time;
	char	*str;
	char	*mess;

	sem_wait(three->sem_global);
	time = ft_itoa((int)(get_time(three)));
	mess = ft_strdup(" is eating\n");
	philo = ft_itoa(i);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo);
	str = ft_strjoin_free_all(str, mess);
	write(1, str, ft_strlen(str));
	three->count_eat++;
	free(str);
	sem_post(three->sem_global);}

void	print_str_dead(t_data *three, int i, long int diff)
{
	char	*philo;
	char	*time;
	char	*str;
	char	*mess;

	sem_wait(three->sem_global);
	mess = ft_strdup(" died\n");
	philo = ft_itoa(i);
	time = ft_itoa((int)diff);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo);
	str = ft_strjoin_free_all(str, mess);
	write(1, str, ft_strlen(str));
	free(str);
	i = 0;
	while (i < three->nbr_of_philo)
	{
		sem_post(three->sem_eat);
		i++;
	}
}
