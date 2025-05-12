/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:35:25 by tle-saut          #+#    #+#             */
/*   Updated: 2025/04/17 14:29:28 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*---------------------------------INCLUDE------------------------------------*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

/*---------------------------------COULEUR------------------------------------*/

#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

/*---------------------------------STRUCTURE----------------------------------*/

typedef struct s_philo
{
	pthread_t	*threads;
	int			id;
	long		last_action_time;
	long		time_to_sleep;
	long		time_to_eat;
	long		time_last_eat;
	long		time_before_dead;
	int			alive;
}	t_philo;

/*-------------------------------------TIME-----------------------------------*/
long	get_time_ms(void);
void	log_action(t_philo *philo, const char *action);


/*-------------------------------------INIT-----------------------------------*/
void	init_value_philo(char **argv, int nbr, t_philo **philos, int i);
void	free_philo(t_philo *philos, int nbr);
t_philo	*init_philo(char **argv, int nbr);

/*---------------------------FONCTION_UTILITAIRE------------------------------*/
/*---------------------------FONCTION_UTILITAIRE------------------------------*/
/*---------------------------FONCTION_UTILITAIRE------------------------------*/

/*---------------------------FONCTION_UTILITAIRE------------------------------*/
int		atoi_philo(const char *nptr);
void	*routine(void *arg);
char	*ft_itoa(int n);
int		ft_nlen(int n);
