#include "../include/philo_three.h"

int		fill_struct(t_data *three, int argc, char **argv)
{
	if (argc < 5 || argc > 7)
		return (-1);
	if (check_digit(argc, argv) != 0)
		return (-1);
	three->number_of_philo = ft_atoi(argv[1]);
	three->time_to_die = ft_atoi(argv[2]);
	three->time_to_eat = ft_atoi(argv[3]);
	three->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		three->number_of_time = ft_atoi(argv[5]);
	else
		three->number_of_time = -1;
	return (0);
}

void	init_struct(t_data *three)
{
	three->number_of_philo = 0;
	three->time_to_die = 0;
	three->time_to_eat = 0;
	three->time_to_sleep = 0;
	three->number_of_time = 0;
	three->time_start = 0;
	three->time_start = get_time(three);
}