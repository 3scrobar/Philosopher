/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:05:10 by tle-saut          #+#    #+#             */
/*   Updated: 2025/04/16 18:19:00 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	log_action(philo, "🧠 is thinking...");
	sleep(1);

	log_action(philo, "🍝 is eating...");
	sleep(1);

	log_action(philo, "😴 is sleeping...");
	sleep(1);

	return (NULL);
}
