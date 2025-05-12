/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:35:21 by tle-saut          #+#    #+#             */
/*   Updated: 2025/04/17 14:38:06 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_philo	*philos;
	
	if (ac < 5)
		return (printf("Error: Not enough arguments\n"));
		
	int nbr_philo = atoi_philo(av[1]);
	printf("Philosophes: %s\nSleep: %s ms\nEat: %s ms\nDie: %s ms\n", av[1], av[2], av[3], av[4]);
	philos = init_philo(av, nbr_philo);
	free_philo(philos, nbr_philo);
	return (0);
}
