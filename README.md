# 19_philosophers

Summary: In this project, we learn the basics of threading a process and how to
work on the same memory space. we discover how to play with threads, mutex, semaphore and shared memory.

To launch the project:

```git clone https://github.com/evrouche/19_philosophers.git```

```cd 19_philosophers/philo_one ```

```make```

```./philo_one 410 200 200 5```

The first number represente the total amount of time a philosopher can survive without eating. The second and the third respectively, the time it takes to eat and to sleep. And the last one is the number of philosophers arourd the table.

For philo_one:

A number of philosophers are sitting at a round table doing one of three things:
eating, thinking or sleeping. 

While eating, they are not thinking or sleeping, while sleeping, they are not eating
or thinking and of course, while thinking, they are not eating or sleeping. Each time a philosopher has finished eating, he will drop his forks and start sleeping. • When a philosopher is done sleeping, he will start thinking. The simulation stops when a philosopher dies.


The philosophers sit at a circular table with a large bowl of spaghetti in the center. There are one fork between each philosopher, therefore there will be a fork at the right and
at the left of each philosopher. As spaghetti is difficult to serve and eat with a single fork, it is assumed that a
philosopher must eat with two forks, one for each hand. Each philosophers is in a different thread and to avoid philosophers duplicating forks, they have protected state with a
mutex for each of them.
