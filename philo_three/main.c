#include "include/philo_three.h"

int ft_exit(t_data *three)
{
    int i;

    i = 0;
    while (i < three->number_of_philo)
    {
        kill(three->pid[i], 0);
        i++;
    }
    return (0);
}

int init_semaphore(t_data *three)
{
    sem_unlink("fork");
    sem_unlink("global");
    sem_unlink("dead");
    sem_unlink("eat");
    three->dead = sem_open("dead", O_CREAT, 0660, 1);
    if (three->dead == SEM_FAILED)
        return (-1);
    three->global = sem_open("global", O_CREAT, 0660, 1);
    if (three->global == SEM_FAILED)
        return (-1);
    three->fork = sem_open("fork", O_CREAT, 0660, three->number_of_philo);
    if (three->dead == SEM_FAILED)
        return (-1);
    three->eat = sem_open("eat", O_CREAT, 0660, three->number_of_philo);
    if (three->dead == SEM_FAILED)
        return (-1);
    return (1);
}

int creat_frok(t_data *three)
{
    int i;

    i = 0;
    if (init_semaphore(three) < 0)
        return (-1);
    sem_wait(three->dead);
    while (i < three->number_of_philo)
    {
        sem_wait(three->eat);
        i++;
    }
    i = 0;
    while (i < three->number_of_philo)
    {
        three->pid[i] = fork();
        three->name[i] = i;
        if (three->pid[i] == 0)
        {
            pthread_create(&three->check_dead, NULL, &check_time, &three->name[i]);
            routine(three, i);
        }
        i++;
    }
    i = 0;
    if (three->number_of_time != -1)
    {
        while (i < three->number_of_philo)
        {
            sem_wait(three->eat);
            i++;
        }
    }
    if (three->number_of_time == -1)
        sem_wait(three->dead);
    ft_exit(three);
    return (0);
}

int main(int argc, char **argv)
{
    t_data three;

    init_struct(&three);
    if (fill_struct(&three, argc, argv))
        return (-1);
    *static_struct() = &three;
    if (creat_frok(&three) < 0)
        return (-1);
    return (0);
}