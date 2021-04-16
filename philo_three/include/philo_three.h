/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 09:16:31 by edessain          #+#    #+#             */
/*   Updated: 2021/02/26 11:18:13 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_data
{
	int			nbr_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_of_time_each_philo_must_eat;
	long int	t_start;
	int			count_eat;
	int			*has_eat;
	pthread_t	thread;
	pthread_t	thread_time;
	pthread_t	thread_nbr_eat;
	sem_t		*sem_forks;
	sem_t		*sem_global;
	sem_t		*sem_eat;
	long int	last_eat;
	int			status;
	int			*pid;
	int			philo;
}				t_data;

/*
*** Philo_two and main
*/

void			routine(t_data *three);
void			*routine_time(void *arg);
void			*routine_nbr_eat(void *arg);
t_data			*get_struct(void);
int				eating(t_data *three);
int				sleeping(t_data *three);
int				thinking(t_data *three);

/*
*** Utils
*/

int				check_count_eat(void);
int				only_digit(char *str);
int				parse_values(t_data *three, int argc, char **argv);
int				complete_values(t_data *three);
long			get_time(t_data *three);
void			ft_sleep(t_data *three, int time);
int				check_time(t_data *three);

/*
*** Print
*/

void			print_str_dead(t_data *three, int i, long int diff);
void			print_str_eat(t_data *three, int i);
void			print_str(t_data *three, int phi, char *mess);
/*
*** Errors, init and free
*/

int				error_arg(int argc, char **argv);
int				init_struct(t_data *three);
int				free_all(t_data *three);

/*
*** Libft
*/

long long		ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strjoin_free_all(char *s1, char *s2);

#endif
