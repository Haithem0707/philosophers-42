#include "philo_header.h"

int	main(int ac, char **av)
{
	int i;
	t_philo_data *philo;
	if (ac < 5 || ac > 6)
	{
		throw_error(1);

		return (1);
	}
	if (!is_valid(av))
		return (1);
	philo = init_philosophers(ac, av);
	i = -1;
	philo->time_to_start = get_current_time_in_miliseconds();
	while (++i < philo->number_of_the_philo)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
			return (1);
		if (philo->pid[i] == 0)
		{
			philo->index = i + 1;
			philo->time_to_meal = get_current_time_in_miliseconds();
			philosopher_routine(philo);
		}
	}
	program_clean_up(&philo);
	return (0);
}