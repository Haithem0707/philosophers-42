#include "philo_header.h"


void	throw_error(int error_num)
{
	if (error_num == 1)
		ft_putstr_fd(YELLOW "The number of argument should be 5 " EMOJI_FIRE,
			2);
	if (error_num == 2)
		ft_putstr_fd(YELLOW "Input It's not Number Or the philosopher is more than 200 or less Than 0" EMOJI_FIRE,
			2);
	if (error_num == 3)
		ft_putstr_fd(YELLOW "Input It's not Number Or The Time to Die is less than 0" EMOJI_FIRE,
			2);
	if (error_num == 4)
		ft_putstr_fd(YELLOW "Input It's not Number Or The Time to Eat is less than 0" EMOJI_FIRE,
			2);
	if (error_num == 5)
		ft_putstr_fd(YELLOW "Input It's not Number Or The Time to Sleep is less than 0" EMOJI_FIRE,
			2);
	if (error_num == 6)
		ft_putstr_fd(YELLOW "Input It's not Number Or The Philo must eat is less than 0" EMOJI_FIRE,
			2);
	if (error_num == 7)
		ft_putstr_fd(YELLOW "The Function GetTimeofday() get fiel" EMOJI_FIRE,
			2);
}

bool	is_number(char *input)
{
	while (*input)
	{
		if (*input < '0' || *input > '9')
			return (false);
		input++;
	}
	return (true);
}
bool	is_valid(char **av)
{
	if (ft_atoi(av[1]) > PHILO_MAX || ft_atoi(av[1]) <= 0 || !is_number(av[1]))
		return (throw_error(2), false);
	if (ft_atoi(av[2]) <= 0 || !is_number(av[2]))
		return (throw_error(2), false);
	if (ft_atoi(av[3]) <= 0 || !is_number(av[3]))
		return (throw_error(2), false);
	if (ft_atoi(av[4]) <= 0 || !is_number(av[4]))
		return (throw_error(2), false);
	if (av[5] && (ft_atoi(av[5]) <= 0 || !is_number(av[5])))
		return (throw_error(2), false);
	return (true);
}
