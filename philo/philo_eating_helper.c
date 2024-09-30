/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:29:45 by hbendjab          #+#    #+#             */
/*   Updated: 2024/09/30 19:39:15 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_header.h"

int	take_fork(pthread_mutex_t *fork, pthread_mutex_t *fork_mutex,
		int *fork_taken, t_philo_data *philos)
{
	pthread_mutex_lock(fork_mutex);
	if (*fork_taken == 0)
	{
		*fork_taken = 1;
		pthread_mutex_unlock(fork_mutex);
		pthread_mutex_lock(fork);
		philos_status(CYAN "Has taken a fork 🍴", philos, philos->id);
		return (1);
	}
	pthread_mutex_unlock(fork_mutex);
	return (0);
}

int	take_forks(t_philo_data *philos)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	pthread_mutex_t	*first_mutex;
	pthread_mutex_t	*second_mutex;

	if (philos->id % 2 == 0)
	{
		first_fork = philos->l_fork;
		second_fork = philos->r_fork;
		first_mutex = philos->l_fork_taken_mutex;
		second_mutex = philos->r_fork_taken_mutex;
	}
	else
	{
		first_fork = philos->r_fork;
		second_fork = philos->l_fork;
		first_mutex = philos->r_fork_taken_mutex;
		second_mutex = philos->l_fork_taken_mutex;
	}
	if (!take_fork(first_fork, first_mutex, &philos->l_fork_taken, philos)
		|| !take_fork(second_fork, second_mutex, &philos->r_fork_taken, philos))
		return (release_fork(first_fork, first_mutex, &philos->l_fork_taken),
			0);
	return (1);
}
