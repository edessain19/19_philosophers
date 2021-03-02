#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct		s_philo_three
{
    int				number_of_philo;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				number_of_time;
    long int        time_start;
    int             *pid;
    int             *name;
    int             iter;
    int             statut;
    int             last_eat;
    pthread_t	    check_dead;
    sem_t	        *fork;
    sem_t	        *global;
    sem_t	        *dead;
}					t_data;

int     main(int argc, char **argv);
int		fill_struct(t_data *three, int argc, char **argv);
void	init_struct(t_data *three);
int     malloc_struct(t_data *three);
int     init_semaphore(t_data *three);
int		check_digit(int argc, char **argv);

/*
** tools.c
*/
t_data	**static_struct(void);
long	get_time(t_data *three);
void	ft_sleep(t_data *three, int time);

/*
** ft_action.c
*/

void	eating(t_data *three, int i);
void	sleeping(t_data *three, int i);
void	*check_time(void *arg);
int 	*routine(t_data *three, int i);

/*
** ft_libft.c
*/

char			*ft_itoa(int n);
size_t		    ft_strlen(const char *s);
int		        ft_isdigit(int c);
int			    ft_atoi(const char *str);
char	        *ft_strdup(const char *s1);
char		    *ft_strjoin(char const *s1, char const *s2);
char	        *ft_strjoin_free(char *s1, char *s2);
char	        *ft_strjoin_free_all(char *s1, char *s2);

/*
** ft_print.c
*/

void	ft_print_str(long int time, int philo, char *message);
void	ft_print_fork(long int time, int philo);
void	ft_print_think(long int time, int philo);
void	ft_print_dead(long int time, int philo);

#endif