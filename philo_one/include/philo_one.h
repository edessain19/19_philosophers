/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by edessain          #+#    #+#             */
/*   Updated: 2021/03/02 14:51:20 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_time_each_philo_must_eat;
	pthread_t		*thread;
	pthread_t		thread_time;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	global_mutex;
	pthread_mutex_t	dead_mutex;
	int				*count_eat;
	int				*has_eat;
	int				*iter;
	long int		*last_eat;
	long int		t_start;
	int				status;
}					t_data;

/*
*** Philo_one
*/

void				*routine(void *arg);
void				*routine_time(void *arg);
int					check_count_eat(void);
t_data				*get_struct(void);

/*
*** Utils
*/

int					print_array(t_data *one);
int					init_struct(t_data *one);
int					parse_values(t_data *one, int argc, char **argv);
int					complete_values(t_data *one);
long				get_time(t_data *one);
void				print_str_dead(t_data *one, int i, long int diff);
void				print_str_eat(t_data *one, int i);
void				print_str(t_data *one, int phi, char *mess);
void				ft_sleep(t_data *one, int time);

/*
*** Errors and Free
*/

int					only_digit(char *str);
int					error_arg(int argc, char **argv);
int					ft_free_str(char **str, int result);
int					free_all(t_data *one);
int					ft_free_int(int i, int result);
int					check_time(t_data *one);
//static char			*ft_zero(void);

/*
*** Libft
*/

char				*ft_itoa(int n);
long long			ft_atoi(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strjoin_free_all(char *s1, char *s2);

#endif
