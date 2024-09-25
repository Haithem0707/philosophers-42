#include "philo_header.h"

void	init_input_from_user(t_philo_data *philo, char **av)
{
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->num_of_philos = ft_atoi(av[1]);
	if (av[5])
		philo->num_time_to_eat = ft_atoi(av[5]);
	else
		philo->num_time_to_eat = -1;
}

// init philos

void	init_philosophers(t_philo_data *philos, t_control *program,
		pthread_mutex_t *fork, pthread_mutex_t *fork_taken, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_input_from_user(&philos[i], av);
		philos[i].start_time = get_current_time_in_miliseconds();
		philos[i].last_meal = get_current_time_in_miliseconds();
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead = &program->dead_flag;
		philos[i].l_fork = &fork[i];
		philos[i].l_fork_taken = 0;
		philos[i].r_fork = (i == 0) ? &fork[philos[i].num_of_philos
			- 1] : &fork[i - 1];
		philos[i].r_fork_taken = 0;
		philos[i].r_fork_taken_mutex = &fork_taken[i];
		philos[i].l_fork_taken_mutex = &fork_taken[(i + 1)
			% philos[i].num_of_philos];
		i++;
	}
}

void	init_fork(pthread_mutex_t *fork, pthread_mutex_t *fork_taken,
		int number_of_philos)
{
	int	i;

	i = 0;
	while (i < number_of_philos)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	i = 0;
	while (i < number_of_philos)
	{
		pthread_mutex_init(&fork_taken[i], NULL);
		i++;
	}
}
void	init_control(t_control *program, t_philo_data *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}
