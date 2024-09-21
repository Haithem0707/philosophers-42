#include "philo_header.h"


bool	is_dead_daily_check(t_philo_data *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), true);
	pthread_mutex_unlock(philo->dead_lock);
	return (false);
}

void	eating(t_philo_data *philos)
{
	
	pthread_mutex_lock(philos->r_fork);
	philos_status(CYAN "Has taken a fork" FORKING, philos, philos->id);
	if (philos->num_of_philos == 1)
	{
		ft_usleep(philos->time_to_die);
		pthread_mutex_unlock(philos->r_fork);
		return ;
	}
	pthread_mutex_lock(philos->l_fork);
	philos_status(CYAN "Has taken a fork" FORKING, philos, philos->id);
	philos->eating = 1;
	philos_status(BLUE "is eating " EATING, philos, philos->id);
    pthread_mutex_lock(philos->meal_lock);
    philos->last_meal = get_current_time_in_miliseconds();
    philos->meals_eaten++;
    pthread_mutex_unlock(philos->meal_lock);
    ft_usleep(philos->time_to_eat);
    philos->eating = 0;
    pthread_mutex_unlock(philos->l_fork);
    pthread_mutex_unlock(philos->r_fork);
}
void	thinking(t_philo_data *philos)
{
	 pthread_mutex_lock(philos->meal_lock);
    philos->last_meal = get_current_time_in_miliseconds();
    pthread_mutex_unlock(philos->meal_lock);
	philos_status(MAGENTA "is Thinking" THINKING, philos, philos->id);
}
void	sleeping(t_philo_data *philos)
{
	philos_status(GREEN "is sleeping" SLEEPING, philos, philos->id);
	ft_usleep(philos->time_to_sleep);
}

void	*philos_daily_routine(void *pointer)
{
	t_philo_data *philos = (t_philo_data *)pointer;

	if (philos->id % 2 == 0)
		ft_usleep(1);
	

	while (!is_dead_daily_check(philos))
	{	
		eating(philos);
		sleeping(philos);
		thinking(philos);
	}
	return (pointer);
}