/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:14:32 by edessain          #+#    #+#             */
/*   Updated: 2021/02/18 18:28:48 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

void	ft_print_str(long int time, int philo, char *message)
{
	char	*dest;
	char	*time_philo;
	char	*nb_philo;
	t_data	*two;

	two = *static_struct();
	time_philo = ft_itoa((int)time);
	nb_philo = ft_itoa(philo);
	dest = ft_strjoin_free(time_philo, " ");
	dest = ft_strjoin_free_all(dest, nb_philo);
	dest = ft_strjoin_free_all(dest, message);
	sem_wait(two->global);
    write(1, dest, ft_strlen(dest));
	sem_post(two->global);
    free(dest);
}

void	ft_print_fork(long int time, int philo)
{
	char	*dest;
	char	*time_philo;
	char	*nb_philo;
	char	*msg;
	t_data	*two;

	two = *static_struct();
	msg = ft_strdup(" has taken a fork\n");
	time_philo = ft_itoa((int)time);
	nb_philo = ft_itoa(philo);
	dest = ft_strjoin_free(time_philo, " ");
	dest = ft_strjoin_free_all(dest, nb_philo);
	dest = ft_strjoin_free_all(dest, msg);
	sem_wait(two->global);
    write(1, dest, ft_strlen(dest));
    sem_post(two->global);
	free(dest);
}

void	ft_print_eat(long int time, int philo)
{
	char	*dest;
	char	*time_philo;
	char	*nb_philo;
	char	*msg;
	t_data	*two;

	two = *static_struct();
	msg = ft_strdup(" is eating\n");
	time_philo = ft_itoa((int)time);
	nb_philo = ft_itoa(philo);
	dest = ft_strjoin_free(time_philo, " ");
	dest = ft_strjoin_free_all(dest, nb_philo);
	dest = ft_strjoin_free_all(dest, msg);
	sem_wait(two->global);
    two->nb_of_meals++;
    write(1, dest, ft_strlen(dest));
	sem_post(two->global);
    free(dest);
}

void	ft_print_dead(long int time, int philo)
{
	char	*dest;
	char	*time_philo;
	char	*nb_philo;
	char	*msg;
	t_data	*two;

	two = *static_struct();
	msg = ft_strdup(" died\n");
	time_philo = ft_itoa((int)time);
	nb_philo = ft_itoa(philo);
	dest = ft_strjoin_free(time_philo, " ");
	dest = ft_strjoin_free_all(dest, nb_philo);
	dest = ft_strjoin_free_all(dest, msg);
	sem_wait(two->global);
    write(1, dest, ft_strlen(dest));
    sem_post(two->dead);
	free(dest);
}
