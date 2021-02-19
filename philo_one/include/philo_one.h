#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct      s_philo_one
{
    int             number_of_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             number_of_time;
//	int 			*iter;
    pthread_t       *philo;
    pthread_mutex_t *mutex;
    int             *name;
	long    		*last_eat;
	int 			statut;
    long int        time_start;
}                   t_data;

int     main();
void    init_struct(t_data *one);

/*
** ft_fill_the_struct.c
*/

int     check_digit(int argc, char **argv);
int     fill_struct(t_data *one, int argc, char **argv);
void    init_struct(t_data *one);

/*
** tools.c
*/

long    get_time(void);
t_data   **static_struct(void);
int	    ft_isdigit(int c);
int     ft_atoi(const char *str);

/*
** ft_action.c
*/
void    *routine(void *arg);
void 	*check_time(void *arg);
void 	eating(t_data *one, int i);
void 	sleeping(t_data *one, int i);
void 	thinking(t_data *one, int i);





#endif
