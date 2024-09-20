#include "philo_header.h"
#include <stdio.h>

void	philos_status(char *str, t_philo_data *philos, int philos_id)
{
	size_t	time;

	pthread_mutex_lock(philos->write_lock);
	time = get_current_time_in_miliseconds() - philos->start_time;
	if (!is_dead_daily_check(philos)){
		printf("%zu %d %s\n", time, philos_id, str);
	}
	pthread_mutex_unlock(philos->write_lock);
		
}

bool	philos_dead_or_not(t_philo_data *philos, size_t time_to_die)
{
	pthread_mutex_lock(philos->meal_lock);
	if (get_current_time_in_miliseconds() - philos->last_meal >= time_to_die
		&& philos->eating == 0)
		return (pthread_mutex_unlock(philos->meal_lock), true);
	pthread_mutex_unlock(philos->meal_lock);
	return (false);
}

bool	is_dead(t_philo_data *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		if (philos_dead_or_not(&philos[i], philos[i].time_to_die))
		{
			philos_status(YELLOW "died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (true);
		}
		i++;
	}
	return (false);
}
bool	is_eat(t_philo_data *philos)
{
	int	i;
	int	eated;

	i = 0;
	eated = 0;
	if (philos[0].num_of_philos == -1)
		return (false);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		
		if (philos[i].meals_eaten >= philos[i].num_time_to_eat)
			eated++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (eated == philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (true);
	}
	return (false); 
}

void	*project_manager(void *pointer)
{
	t_philo_data	*philos;

	philos = (t_philo_data *)pointer;
	while (1)
		if (is_dead(philos) || is_eat(philos))
			 break ;

	return (pointer);
}
