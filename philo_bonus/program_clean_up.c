#include "philo_header.h"

void	program_clean_up(t_philo_data **philo)
{
	t_philo_data	*tmp;
	int				i;
	int				status;

	tmp = *philo;
	i = 0;
	while (i < tmp->number_of_the_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < tmp->number_of_the_philo)
				kill(tmp->pid[i], SIGKILL);
			break ;
		}
		i++;
	}
	sem_close(tmp->sem_fork);
	sem_close(tmp->sem_data);
	sem_close(tmp->sem_write);
	sem_close(tmp->sem_sync);
	sem_unlink("/sem_fork");
	sem_unlink("/sem_write");
	sem_unlink("/sem_sync");
	sem_unlink("/sem_data");
	free(tmp->pid);
	free(tmp);
}
