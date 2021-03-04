#include "../include/philo_three.h"

int		check_digit(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

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
    if (malloc_struct(three) < 0)
        return (-1);
    three->nb_of_meals = three->number_of_time;
	return (0);
}

void	init_struct(t_data *three)
{
	three->number_of_philo = 0;
	three->time_to_die = 0;
	three->time_to_eat = 0;
	three->time_to_sleep = 0;
	three->number_of_time = 0;
    three->statut = -1;
	three->time_start = 0;
	three->time_start = get_time(three);
}

int     malloc_struct(t_data *three)
{
    three->pid = malloc(sizeof(pid_t) * three->number_of_philo);
    if (three->pid == NULL)
        return (-1);
    three->name = malloc(sizeof(int) * three->number_of_philo);
    if (three->name == NULL)
        return (-1);
    memset(three->pid, 0, three->number_of_philo * 8);
    return (0);
}