/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:35:18 by tle-saut          #+#    #+#             */
/*   Updated: 2025/04/17 14:37:45 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*init_philo(char **argv, int nbr)
{
	int		i; 

	t_philo	*philos = malloc(sizeof(t_philo) * nbr);
	if (!philos)
		return (NULL);

	i = 0;
	while (i < nbr)
	{
		init_value_philo(argv, nbr, &philos, i);
		pthread_create(philos[i].threads, NULL, routine, &philos[i]);
		i++;
	}
	return (philos);
}

void	init_value_philo(char **argv, int nbr, t_philo **philos, int i)
{
	long	die;
	long	eat;
	long	sleep;
	
	(void)nbr;
	nbr = atoi(argv[1]);
	die = atol(argv[2]);
	eat = atol(argv[3]);
	sleep = atol(argv[4]);
	philos[i]->id = i + 1;
	philos[i]->time_to_sleep = sleep;
	philos[i]->time_to_eat = eat;
	philos[i]->time_before_dead = die;
	philos[i]->alive = 1;
	philos[i]->threads = malloc(sizeof(pthread_t));
	if (!philos[i]->threads)
		printf("probleme de malloc, au niveau de thread");
}

void	free_philo(t_philo *philos, int nbr)
{
	int	i;
	
	i = 0;
	while (i < nbr)
	{
		pthread_join(*philos[i].threads, NULL);
		free(philos[i].threads);
		i++;
	}
	free(philos);

}
