/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:08:59 by hbendjab          #+#    #+#             */
/*   Updated: 2024/09/30 19:54:52 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_header.h"

void	throw_error(int error_num)
{
	const char	*messages[] = {
		"Invalid error number",
		YELLOW "The number of argument should be 5 " EMOJI_FIRE,
		YELLOW "Check your Input is not valid" EMOJI_FIRE,
		YELLOW "Check your Input is not valid " EMOJI_FIRE,
		YELLOW "Check your Input is not valid" EMOJI_FIRE,
		YELLOW "Check your Input is not valid " EMOJI_FIRE,
		YELLOW "Check your Input is not valid" EMOJI_FIRE,
		YELLOW "The function gettimeofday() failed " EMOJI_FIRE
	};

	if (error_num > 0 && error_num < 8)
		ft_putstr_fd((char *)messages[error_num], 2);
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
