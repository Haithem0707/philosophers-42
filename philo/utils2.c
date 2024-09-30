/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:40:48 by hbendjab          #+#    #+#             */
/*   Updated: 2024/09/30 21:01:11 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_header.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_usleep(size_t milliseconds, t_philo_data *philos)
{
	size_t	start;

	start = get_current_time_in_miliseconds();
	while ((get_current_time_in_miliseconds() - start) < milliseconds)
	{
		if (is_dead_daily_check(philos))
			return (1);
		usleep(500);
	}
	return (0);
}

size_t	get_current_time_in_miliseconds(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		throw_error(7);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
