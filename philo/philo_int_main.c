#include "philo_header.h"

int	main(int ac, char **av)
{
	t_control control;
	t_philo_data philos[PHILO_MAX];
	pthread_mutex_t fork[PHILO_MAX];
	pthread_mutex_t fork_taken[PHILO_MAX];
	if (ac < 5 || ac > 6)
	{
		throw_error(1);
		return (1);
	}
	if (!is_valid(av))
		return (1);
	init_control(&control, philos);
	init_fork(fork, fork_taken, ft_atoi(av[1]));
	init_philosophers(philos, &control, fork, fork_taken, av);
	thread_creation(&control, fork);
	return (0);
}