#include "philo_header.h"

bool	is_dead_daily_check(t_philo_data *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), true);
	pthread_mutex_unlock(philo->dead_lock);
	return (false);
}

int	take_fork(pthread_mutex_t *fork, pthread_mutex_t *fork_mutex,
		int *fork_taken, t_philo_data *philos, char *status_msg)
{
	pthread_mutex_lock(fork_mutex);
	if (*fork_taken == 0)
	{
		*fork_taken = 1;
		pthread_mutex_unlock(fork_mutex);
		pthread_mutex_lock(fork);
		philos_status(status_msg, philos, philos->id);
		return (1);
	}
	pthread_mutex_unlock(fork_mutex);
	return (0);
}

void	release_fork(pthread_mutex_t *fork, pthread_mutex_t *fork_mutex,
		int *fork_taken)
{
	pthread_mutex_unlock(fork);
	pthread_mutex_lock(fork_mutex);
	*fork_taken = 0;
	pthread_mutex_unlock(fork_mutex);
}

void	update_meal_status(t_philo_data *philos)
{
	pthread_mutex_lock(philos->meal_lock);
	philos->last_meal = get_current_time_in_miliseconds();
	philos->meals_eaten++;
	pthread_mutex_unlock(philos->meal_lock);
}
void	eating(t_philo_data *philos)
{
	if (!take_fork(philos->r_fork, philos->r_fork_taken_mutex,
			&philos->r_fork_taken, philos, CYAN "Has taken a fork"))
		return ;
	if (philos->num_of_philos == 1)
	{
		ft_usleep(philos->time_to_die, philos);
		release_fork(philos->r_fork, philos->r_fork_taken_mutex,
			&philos->r_fork_taken);
		return ;
	}
	if (!take_fork(philos->l_fork, philos->l_fork_taken_mutex,
			&philos->l_fork_taken, philos, CYAN "Has taken a fork"))
	{
		release_fork(philos->r_fork, philos->r_fork_taken_mutex,
			&philos->r_fork_taken);
		return ;
	}
	philos->eating = 1;
	philos_status(BLUE "is eating " EATING, philos, philos->id);
	update_meal_status(philos);
	ft_usleep(philos->time_to_eat, philos);
	philos->eating = 0;
	release_fork(philos->l_fork, philos->l_fork_taken_mutex,
		&philos->l_fork_taken);
	release_fork(philos->r_fork, philos->r_fork_taken_mutex,
		&philos->r_fork_taken);
}

void	thinking(t_philo_data *philos)
{
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