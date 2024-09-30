/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_int_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:12:49 by hbendjab          #+#    #+#             */
/*   Updated: 2024/09/30 21:16:23 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_header.h"

int	main(int ac, char **av)
{
	t_control		control;
	t_philo_data	philos[PHILO_MAX];
	pthread_mutex_t	fork[PHILO_MAX];
	pthread_mutex_t	fork_taken[PHILO_MAX];
	int				i;

	i = -1;
	if (ac < 5 || ac > 6)
	{
		throw_error(1);
		return (1);
	}
	if (!is_valid(av))
		return (1);
	init_control(&control, philos);
	init_fork(fork, fork_taken, ft_atoi(av[1]));
	while (++i < ft_atoi(av[1]))
	{
		init_input_from_user(&philos[i], av);
	}
	init_philosophers(philos, &control, fork, fork_taken);
	thread_creation(&control, fork, fork_taken);
	destroy_all(NULL, &control, fork, fork_taken);
	return (0);
}
