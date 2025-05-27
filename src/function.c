/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42perpignan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:33:34 by tle-saut          #+#    #+#             */
/*   Updated: 2025/05/01 15:15:30 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	get_timestamp(struct timeval start)
{
	int				timestamp;
	struct timeval	end;

	gettimeofday(&end, NULL);
	timestamp = ((end.tv_sec * 1000000 + end.tv_usec)
			- (start.tv_sec * 1000000 + start.tv_usec)) / 1000;
	return (timestamp);
}

int	ft_atoi(char *str)
{
	int		i;
	int		ret;
	int		neg;

	i = 0;
	ret = 0;
	neg = 1;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		if (str[i++] == '-')
			neg = -1;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		ret = (ret * 10) + (str[i] - 48);
		i++;
	}
	return (ret * neg);
}

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
}

int	check_main(int ac, char **av)
{
	if (ac >= 5)
	{
		if (ac > 5)
		{
			if (ft_strlen(av[4]) > 10)
				return (0);
			else
				return (1);
		}
		if (ft_strlen(av[1]) > 10 || ft_strlen(av[2]) > 10
			|| ft_strlen(av[3]) > 10)
			return (0);
		else
			return (1);
	}
	return (0);
}
