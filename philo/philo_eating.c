/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:25:56 by hbendjab          #+#    #+#             */
/*   Updated: 2024/09/30 19:46:34 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_header.h"

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

int	handle_single_philosopher(t_philo_data *philos)
{
	if (!take_fork(philos->l_fork, philos->l_fork_taken_mutex,
			&philos->l_fork_taken, philos))
		return (0);
	ft_usleep(philos->time_to_die, philos);
	philos_status(RED "has died", philos, philos->id);
	release_fork(philos->l_fork, philos->l_fork_taken_mutex,
		&philos->l_fork_taken);
	return (1);
}

void	eating(t_philo_data *philos)
{
	if (philos->num_of_philos == 1)
	{
		handle_single_philosopher(philos);
		return ;
	}
	if (!take_forks(philos))
		return ;
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
