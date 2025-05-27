/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42perpignan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:33:41 by tle-saut          #+#    #+#             */
/*   Updated: 2025/05/01 15:14:40 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char const *av[])
{
	t_arg		arg;

	if (ac == 5)
		arg.need_eat = -1;
	else if (ac >= 6)
		arg.need_eat = ft_atoi((char *)av[5]);
	if (ac >= 5)
	{
		arg.nb_philo = ft_atoi((char *)av[1]);
		arg.t_dead = ft_atoi((char *)av[2]);
		arg.t_eat = ft_atoi((char *)av[3]);
		arg.t_sleep = ft_atoi((char *)av[4]);
		if (check_main(ac, (char **)av))
			philosopher(arg);
		else
			ft_error("Error\n");
	}
	return (0);
}
