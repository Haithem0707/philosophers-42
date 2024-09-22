#ifndef PHILO_HEADER
# define PHILO_HEADER

# include <sched.h>
#
# define RESET "\x1b[0m"
# define BLACK "\x1b[30m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"

# define EMOJI_WORLD "\U0001F30D"
# define EMOJI_FIRE "\U0001F525"
# define EMOJI_THUMBSUP "\U0001F44D"
# define EMOJI_SMILE "\U0001F60A"
# define EMOJI_CHECK "\U00002705"
# define EMOJI_CROSS "\U0000274C"
# define THINKING "\U0001F914"
# define SLEEPING "\U0001F634"
# define FORKING "\U0001F374"
# define EATING "\U0001F37D"
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>
# define PHILO_MAX 200
typedef struct s_philo_data
{
	pthread_t		thread;
	int				id;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				eating;
	int				meals_eaten;
	size_t			start_time;
	int				num_of_philos;
	size_t			last_meal;
	int				num_time_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo_data;
typedef struct s_control
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo_data	*philos;

}					t_control;
void				ft_putstr_fd(char *s, int fd);
int					ft_atoi(const char *str);
void				throw_error(int error_num);
bool				is_valid(char **user_input);
size_t				get_current_time_in_miliseconds(void);
int					ft_usleep(size_t milliseconds,t_philo_data *philos);
void				init_control(t_control *program, t_philo_data *philos);
void				init_fork(pthread_mutex_t *fork, int number_of_philos);
void				init_philosophers(t_philo_data *philos, t_control *program,
						pthread_mutex_t *fork, char **av);
void				init_input_from_user(t_philo_data *philo, char **av);
void				*project_manager(void *pointer);
void				thread_creation(t_control *program, pthread_mutex_t *fork);
void				*philos_daily_routine(void *pointer);
void				philos_status(char *str, t_philo_data *philos,
						int philos_id);
bool				is_dead(t_philo_data *philos);
void				destroy_all(char *str, t_control *program,
						pthread_mutex_t *fork);

bool				is_dead_daily_check(t_philo_data *philo);
#endif