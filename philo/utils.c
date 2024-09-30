

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

void	destroy_all(char *str, t_control *program, pthread_mutex_t *fork)
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
		i++;
	}
}
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
	struct timeval time;
	if (gettimeofday(&time, NULL) == -1)
		throw_error(7);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}