#include "philo_header.h"

int	check_meals_and_exit(t_philo_data *philo)
{
	sem_wait(philo->sem_sync);
	if (philo->num_eat != -1 && philo->num_eat_count >= philo->num_eat)
	{
		sem_post(philo->sem_sync);
		return (1);
	}
	sem_post(philo->sem_sync);
	return (0);
}

void	handle_philosopher_exit(t_philo_data *philo)
{
	if (philo->die)
		exit(1);
	else
		exit(0);
}

void	*ft_death_check(void *arg)
{
	t_philo_data	*philo;

	philo = (t_philo_data *)arg;
	while (1)
	{
		usleep(100);
		sem_wait(philo->sem_sync);
		if (get_current_time_in_miliseconds()
			- philo->time_to_meal > philo->time_to_die)
		{
			philo->die = 1;
			sem_wait(philo->sem_write);
			printf("%lld %d %s\n", get_current_time_in_miliseconds()
				- philo->time_to_start, philo->index, RED "Died 💀");
			sem_post(philo->sem_sync);
			break ;
		}
		sem_post(philo->sem_sync);
		if (check_meals_and_exit(philo))
			break ;
	}
	handle_philosopher_exit(philo);
	return (NULL);
}

void	philosopher_routine(t_philo_data *philo)
{
	if ((pthread_create(&philo->project_manager, NULL, ft_death_check,
				philo)) != 0)
		program_clean_up(&philo);
	if (philo->index % 2 == 1)
		usleep(1000);
	while (1)
	{
		sem_wait(philo->sem_fork);
		philo_print(philo, GREEN "has taken a fork 🍴 ");
		sem_wait(philo->sem_fork);
		philo_print(philo, YELLOW "has taken a fork 🍴");
		philo_print(philo, "is eating 🍽️");
		ft_usleep(philo->time_to_eat, philo);
		sem_wait(philo->sem_sync);
		philo->time_to_meal = get_current_time_in_miliseconds();
		philo->num_eat_count += 1;
		sem_post(philo->sem_sync);
		sem_post(philo->sem_fork);
		sem_post(philo->sem_fork);
		philo_print(philo, CYAN "is sleeping 😴");
		ft_usleep(philo->time_to_sleep, philo);
		philo_print(philo, BLUE "is thinking 🤔");
	}
	if ((pthread_join(philo->project_manager, NULL)) != 0)
		program_clean_up(&philo);
}
