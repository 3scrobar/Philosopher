/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:11:01 by tle-saut          #+#    #+#             */
/*   Updated: 2025/04/16 18:20:45 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


long get_time_ms(void)
{
	struct timeval time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void log_action(t_philo *philo, const char *action)
{
	long current_time = get_time_ms();
	long elapsed_time = current_time - philo->last_action_time;

	printf("%d %s (last action %ld ms ago)\n", philo->id, action, elapsed_time);

	philo->last_action_time = current_time;
}

