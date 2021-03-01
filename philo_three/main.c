#include "../include/philo_three.h"


int     main(int argc, char **argv)
{
	init_struct(&three);
	if (fill_struct(&three, argc, argv))
		return (-1);

}