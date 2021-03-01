#include "../include/philo_three.h"

void	ft_sleep(t_data *three, int time)
{
	int			i;
	long int	time_now;

	time_now = get_time(three);
	i = 0;
	while (i < 10 * time)
	{
		i++;
		if (get_time(three) - time_now >= time)
			break ;
		usleep(100);
	}
}

long	get_time(t_data *three)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds - three->time_start);
}

t_data	**static_struct(void)
{
	static t_data	*three;

	return (&three);
}