/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:10:48 by hbendjab          #+#    #+#             */
/*   Updated: 2024/09/30 21:20:18 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_header.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					sn;
	unsigned long int	rs;

	i = 0;
	sn = 1;
	rs = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sn = -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		if ((rs > (long long)LONG_MAX / 100) && (sn == 1))
			return (-1);
		else if ((rs > (long long)LONG_MAX / 100) && (sn == -1))
			return (0);
		rs = rs * 10 + str[i] - '0';
		i++;
	}
	return (rs * sn);
}

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

void	destroy_all(char *str, t_control *program, pthread_mutex_t *fork,
		pthread_mutex_t *fork_taken)
{
	int	i;

	i = 0;
	if (str)
		ft_putstr_fd(str, 2);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (i < program->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&fork[i]);
		pthread_mutex_destroy(&fork_taken[i]);
		i++;
	}
}
