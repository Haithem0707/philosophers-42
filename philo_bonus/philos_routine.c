#include "philo_header.h"
#include <semaphore.h>

void	*ft_death_check(void *arg)
{
	t_philo_data	*philo;

	philo = (t_philo_data *)arg;
	while (1)
	{
		
		usleep(100);
		if (get_current_time_in_miliseconds()
			- philo->time_to_meal > philo->time_to_die)
		{
			philo->die = 1;
			sem_wait(philo->sem_write);
			printf("%lld %d %s\n", get_current_time_in_miliseconds()
				- philo->time_to_start, philo->index, RED "Died 💀");
				
			philo->stop = 1;
			break ;
		}
		if (philo->num_eat != -1 && philo->num_eat_count >= philo->num_eat)
		{
			philo->stop = 1;
			break ;
		}
	}
	if (philo->die)
		exit(1);
	else
		exit(0);
}

void	philosopher_routine(t_philo_data *philo)
{
	pthread_create(&philo->project_manager, NULL, ft_death_check, philo);
	if (philo->index % 2 == 1)
		usleep(1000);
	while (1)
	{
		sem_wait(philo->sem_fork);
		philo_print(philo, "has taken a fork 🍴 ");
		sem_wait(philo->sem_fork);
		philo_print(philo, "has taken a fork 🍴");
		philo_print(philo, "is eating 🍽️");
		ft_usleep(philo->time_to_eat, philo);
		sem_wait(philo->sem_sync);
		philo->time_to_meal = get_current_time_in_miliseconds();
		philo->num_eat_count += 1;
		sem_post(philo->sem_sync);
		sem_post(philo->sem_fork);
		sem_post(philo->sem_fork);
		philo_print(philo, "is sleeping 😴");
		ft_usleep(philo->time_to_sleep, philo);
		philo_print(philo, "is thinking 🤔");
	}
	pthread_join(philo->project_manager, NULL);
}