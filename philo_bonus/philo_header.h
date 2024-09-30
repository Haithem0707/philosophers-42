/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:25:28 by hbendjab          #+#    #+#             */
/*   Updated: 2024/09/30 21:35:27 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_HEADER_H
# define PHILO_HEADER_H
# define RESET "\x1b[0m"
# define BLACK "\x1b[30m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"

# define EMOJI_FIRE "\U0001F525"
# define PHILO_MAX 200

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philo_data
{
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				number_of_the_philo;
	int				num_of_the_fork;
	int				num_eat;
	int				num_eat_count;
	int				die;
	int				*pid;
	sem_t			*sem_write;
	sem_t			*sem_fork;
	sem_t			*sem_data;
	sem_t			*sem_sync;
	sem_t			*time_data;
	long long int	time_to_start;
	int				index;
	long long int	time_to_meal;
	pthread_t		project_manager;

}					t_philo_data;
void				ft_putstr_fd(char *s, int fd);
int					ft_atoi(const char *str);
void				throw_error(int error_num);
bool				is_valid(char **user_input);
long long			get_current_time_in_miliseconds(void);
void				ft_usleep(long long milliseconds, t_philo_data *philo);
t_philo_data		*init_philosophers(int ac, char **av);
void				philosopher_routine(t_philo_data *philo);
void				program_clean_up(t_philo_data **philo);
void				program_clean_up2(t_philo_data **philo);
void				philo_print(t_philo_data *philo, char *str);
#endif