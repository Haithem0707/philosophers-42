#include "philo_header.h"

bool	is_dead_daily_check(t_philo_data *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), true);
	pthread_mutex_unlock(philo->dead_lock);
	return (false);
}
void	lock_fork(pthread_mutex_t *fork, int *fork_taken, t_philo_data *philos,
		char *status)
{
	pthread_mutex_lock(fork);
	if (!(*fork_taken))
	{
		*fork_taken = 1;
		philos_status(status, philos, philos->id);
	}
	pthread_mutex_unlock(fork);
}

void	unlock_fork(pthread_mutex_t *fork, int *fork_taken)
{
	pthread_mutex_lock(fork);
	*fork_taken = 0;
	pthread_mutex_unlock(fork);
}
void	eating(t_philo_data *philos)
{
	lock_fork(philos->r_fork, &philos->r_fork_taken, philos,
		CYAN "Has taken a fork" FORKING);
	if (philos->num_of_philos == 1)
	{
		ft_usleep(philos->time_to_die, philos);
		unlock_fork(philos->r_fork, &philos->r_fork_taken);
		return ;
	}
	lock_fork(philos->l_fork, &philos->l_fork_taken, philos,
		CYAN "Has taken a fork" FORKING);
	philos->eating = 1;
	philos_status(BLUE "is eating " EATING, philos, philos->id);
	pthread_mutex_lock(philos->meal_lock);
	philos->last_meal = get_current_time_in_miliseconds();
	philos->meals_eaten++;
	pthread_mutex_unlock(philos->meal_lock);
	ft_usleep(philos->time_to_eat, philos);
	unlock_fork(philos->r_fork, &philos->r_fork_taken);
	unlock_fork(philos->l_fork, &philos->l_fork_taken);
	philos->eating = 0;
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
	ft_usleep(philos->time_to_sleep, philos);
}

void	*philos_daily_routine(void *pointer)
{
	t_philo_data *philos = (t_philo_data *)pointer;

	if (philos->id % 2 == 0)
		ft_usleep(1, philos);

	while (!is_dead_daily_check(philos))
	{
		eating(philos);
		sleeping(philos);
		thinking(philos);
	}
	return (pointer);
}