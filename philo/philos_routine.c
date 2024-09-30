/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:12:44 by hbendjab          #+#    #+#             */
/*   Updated: 2024/09/30 19:25:48 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_header.h"

bool	is_dead_daily_check(t_philo_data *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), true);
	pthread_mutex_unlock(philo->dead_lock);
	return (false);
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
	t_philo_data	*philos;

	philos = (t_philo_data *)pointer;
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
