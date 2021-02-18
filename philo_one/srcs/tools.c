/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:14:32 by edessain          #+#    #+#             */
/*   Updated: 2021/02/18 16:31:31 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

t_data   **static_struct(void)
{
    static t_data    *one;
    return (&one);
}

int		ft_isdigit(int c)
{
	if (c < '0' || '9' < c)
		return (0);
	return (1);
}

int    ft_atoi(const char *str)
{
    int                    i;
    int                    signe;
    unsigned long long    prev;
    unsigned long long    digit;

    i = 0;
    prev = 0;
    digit = 0;
    signe = 1;
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
        || str[i] == '\v' || str[i] == '\f')
        i++;
    if (str[i] == '-' || str[i] == '+')
        signe = (str[i++] == '-') ? -1 : 1;
    while (str[i] > 47 && str[i] < 58)
    {
        digit = digit * 10 + (str[i++] - '0');
        if (digit < prev || digit >= 9223372036854775807)
            return ((signe == -1) ? 0 : -1);
        prev = digit;
    }
    return (digit * signe);
}

void    init_struct(t_data *one)
{
    one->number_of_philo = 0;
    one->time_to_die = 0;
    one->time_to_eat = 0;
    one->time_to_sleep = 0;
    one->number_of_time = 0; //facultatif
	one->statut = 0;
}
