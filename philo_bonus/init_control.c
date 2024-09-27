#include "philo_header.h"


t_philo_data *init_philosophers(t_control *control)
{
	t_philo_data	*philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(t_philo_data) * control->philo_number);
	control->death = NULL;
	control->stop = NULL;
	control->message = NULL;
	control->forks = NULL;
	while (++i < control->philo_number)
		input_from_user(control, philo, i);
	return (philo);
}

void	input_from_user(t_control *control, t_philo_data *philo, int i)
{
	philo[i].index = i;
	philo[i].is_dead = NO;
	philo[i].data = control;
	philo[i].pid = -1;
	if (control->eat_counter == -1)
		philo[i].eat_counter = -1;
	else
		philo[i].eat_counter = control->eat_counter;
}


