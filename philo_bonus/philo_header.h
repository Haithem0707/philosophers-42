#ifndef PHILO_HEADER
# define PHILO_HEADER
# include <semaphore.h>
# include <sys/types.h>
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
#include <semaphore.h>
# define PHILO_MAX 200

typedef struct s_control
{
	sem_t			*forks;
	sem_t			*message;
	sem_t			*death;
	sem_t			*stop;
	unsigned int	start;
	int				philo_number;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_think;
	int				time_to_eat;
	int				eat_counter;
	int				max_eat;
	int				current_eat;

}					t_control;
typedef struct s_philo_data
{
	t_control		*data;
	pid_t			pid;
	unsigned int	eating_time;
	unsigned int	next_meal;
	int				index;
	int				is_dead;
	int				eat_counter;
}					t_philo_data;
void				ft_putstr_fd(char *s, int fd);
int					ft_atoi(const char *str);
void				throw_error(int error_num);
bool				is_valid(char **user_input);
size_t				get_current_time_in_miliseconds(void);
int					ft_usleep(size_t milliseconds);

#endif