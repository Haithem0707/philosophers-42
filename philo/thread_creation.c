/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:10:58 by hbendjab          #+#    #+#             */
/*   Updated: 2024/09/30 21:21:44 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_header.h"

void	thread_creation(t_control *program, pthread_mutex_t *fork,
		pthread_mutex_t *fork_taken)
{
	pthread_t	supervisor;
	int			i;

	i = -1;
	if (pthread_create(&supervisor, NULL, &project_manager,
			program->philos) != 0)
		destroy_all(YELLOW "The Thread creation failed in line 11" EMOJI_FIRE,
			program,
			fork,
			fork_taken);
	while (++i < program->philos[0].num_of_philos)
	{
		pthread_create(&program->philos[i].thread, NULL, &philos_daily_routine,
			&program->philos[i]);
	}
	pthread_join(supervisor, NULL);
	i = -1;
	while (++i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destroy_all(YELLOW "The Thread join failed in line 37" EMOJI_FIRE,
				program,
				fork,
				fork_taken);
	}
}
