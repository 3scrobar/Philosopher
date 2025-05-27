/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42perpignan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:33:04 by tle-saut          #+#    #+#             */
/*   Updated: 2025/05/01 15:15:44 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static t_philo	*check_value(t_philo *philo)
{
	int		time;

	time = 0;
	while (philo->balise != 1 && protect_check(philo))
	{
		pthread_mutex_lock(philo->shared->dead);
		time = get_timestamp(philo->tmstp);
		if ((time - philo->last_meal) > (philo->shared->arg.t_dead + 1))
		{
			*(philo->shared->is_dead) = 1;
			pthread_mutex_lock(philo->shared->write_protect);
			printf("\033[31m%d Philo %d died 💀\n\033[0m",
				get_timestamp(philo->tmstp), philo->index);
			pthread_mutex_unlock(philo->shared->write_protect);
		}
		pthread_mutex_unlock(philo->shared->dead);
		philo = philo->next;
	}
	return (philo);
}

static int	monitoring_eat(t_philo *philo)
{
	if (philo->shared->arg.need_eat < 0)
		return (0);
	while (philo->balise != 1)
	{
		pthread_mutex_lock(&(philo->count_protect));
		if (philo->count < philo->shared->arg.need_eat)
		{
			pthread_mutex_unlock(&(philo->count_protect));
			return (0);
		}
		pthread_mutex_unlock(&(philo->count_protect));
		philo = philo->next;
	}
	return (1);
}

void	monitoring(t_philo *philo)
{
	t_philo	*start;

	start = philo;
	while (protect_check(philo))
	{
		if (monitoring_eat(start))
		{
			pthread_mutex_lock(philo->shared->dead);
			*(start->shared->is_dead) = 1;
			pthread_mutex_unlock(philo->shared->dead);
			usleep(2000);
			pthread_mutex_lock(philo->shared->write_protect);
			printf("\033[31mEND Philos as eat %d times\033[0m\n", philo->count);
			pthread_mutex_unlock(philo->shared->write_protect);
			break ;
		}
		philo = check_value(philo);
		if (philo->balise == 1)
			philo = philo->next;
	}
}
