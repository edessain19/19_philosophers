#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct		s_philo_three
{
    int				number_of_philo;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				number_of_time;
    long int        time_start;

}					t_data;

int     main(int argc, char **argv);




endif