#include "philo_header.h"
#include <pthread.h>
#include <stdio.h>
#include <time.h>

void	thread_creation(t_control *program, pthread_mutex_t *fork)
{
	pthread_t	supervisor;
	int			i;

	i = 0;
	if (pthread_create(&supervisor, NULL, &project_manager, program->philos) != 0 )
            destroy_all(YELLOW"The Thread creation failed in line 11" EMOJI_FIRE, program, fork);
		i = 0;
	while (i < program->philos[0].num_of_philos)
	{		
		pthread_create(&program->philos[i].thread, NULL, &philos_daily_routine,
			&program->philos[i]);
			i++;
	}
	pthread_join(supervisor, NULL);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		pthread_join(program->philos[i].thread, NULL);
		i++;
	}
}
