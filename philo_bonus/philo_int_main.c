#include "philo_header.h"

int	main(int ac, char **av)
{

	if (ac < 5 || ac > 6)
	{
		throw_error(1);
		return (1);
	}
	if (!is_valid(av))
		return (1);

}