/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:25:22 by hbendjab          #+#    #+#             */
/*   Updated: 2024/09/30 21:38:15 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_header.h"

void	philo_print(t_philo_data *philo, char *str)
{
	sem_wait(philo->sem_write);
	printf("%lld %d %s\n", get_current_time_in_miliseconds()
		- philo->time_to_start, philo->index, str);
	sem_post(philo->sem_write);
}

t_philo_data	*input_from_user(int ac, char **av)
{
	t_philo_data	*philo_tmp;

	philo_tmp = malloc(sizeof(t_philo_data));
	if (!philo_tmp)
		ft_putstr_fd("The malloc failed", 2);
	philo_tmp->number_of_the_philo = ft_atoi(av[1]);
	philo_tmp->num_of_the_fork = philo_tmp->number_of_the_philo;
	philo_tmp->time_to_die = atoi(av[2]);
	philo_tmp->time_to_eat = atoi(av[3]);
	philo_tmp->time_to_sleep = atoi(av[4]);
	philo_tmp->num_eat = -1;
	if (ac == 6)
	{
		philo_tmp->num_eat = atoi(av[5]);
	}
	philo_tmp->num_eat_count = 0;
	philo_tmp->die = 0;
	return (philo_tmp);
}

t_philo_data	*init_philosophers(int ac, char **av)
{
	t_philo_data	*philo_tmp;

	philo_tmp = input_from_user(ac, av);
	philo_tmp->pid = malloc(sizeof(int) * philo_tmp->num_of_the_fork);
	if (!philo_tmp->pid)
		ft_putstr_fd("The malloc if field in the line 35", 2);
	sem_unlink("/sem_fork");
	sem_unlink("/sem_write");
	sem_unlink("/sem_data");
	sem_unlink("/sync_sem");
	philo_tmp->sem_sync = sem_open("/sync_sem", O_CREAT, 0644, 1);
	philo_tmp->sem_write = sem_open("/sem_write", O_CREAT, 0664, 1);
	philo_tmp->sem_data = sem_open("/sem_data", O_CREAT, 0644, 1);
	philo_tmp->sem_fork = sem_open("/sem_fork", O_CREAT, 0664,
			philo_tmp->num_of_the_fork);
	return (philo_tmp);
}
