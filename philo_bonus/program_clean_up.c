/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_clean_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:25:45 by hbendjab          #+#    #+#             */
/*   Updated: 2024/09/30 21:40:17 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

void	program_clean_up2(t_philo_data **philo)
{
	t_philo_data	*tmp;

	tmp = *philo;
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
