#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct		s_philo_two
{
    int				number_of_philo;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				number_of_time;
    pthread_t		*philo;
    pthread_t	    check_dead;
    sem_t	        *fork;
    sem_t	        *global;
    sem_t	        *dead;
    int				*name;
    int             *iter;
	long			*last_eat;
	int				statut;
    int             nb_of_meals;
    long int		time_start;
}					t_data;

int					main();
void				init_struct(t_data *two);

/*
** ft_fill_the_struct.c
*/

int					check_digit(int argc, char **argv);
int					fill_struct(t_data *two, int argc, char **argv);
void				init_struct(t_data *two);

/*
** tools.c
*/

void				destroy_sem(t_data *two);
long				get_time(t_data *two);
t_data				**static_struct(void);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
void				ft_print_str(long int time,
							int philo, char *message);
void				ft_print_dead(long int time, int philo);
void				ft_print_fork(long int time, int philo);
void				ft_print_think(long int time, int philo);
void				ft_sleep(t_data *one, int time);
void                ft_free(t_data *one);



/*
** ft_action.c
*/
void    *routine(void *arg);
void 	*check_time(void *arg);
int 	check_iter(t_data *one, int i);
void 	eating(t_data *two, int i);
void 	sleeping(t_data *two, int i);

/*
** ft_libft.c
*/

char	        *ft_strjoin(char const *s1, char const *s2);
char	        *ft_strjoin_free_all(char *s1, char *s2);
char	        *ft_strjoin_free(char *s1, char *s2);
char	        *ft_strdup(const char *s1);
int             ft_atoi(const char *str);
char			*ft_itoa(int n);
int		        ft_isdigit(int c);
size_t		    ft_strlen(const char *s);

#endif
