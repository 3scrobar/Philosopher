/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42perpignan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:29:52 by tle-saut          #+#    #+#             */
/*   Updated: 2025/05/01 14:51:13 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*---------------------------------INCLUDE------------------------------------*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

/*---------------------------------STRUCTURE----------------------------------*/

typedef struct s_arg
{
	int		nb_philo;
	int		t_dead;
	int		t_eat;
	int		t_sleep;
	int		need_eat;
}	t_arg;

typedef struct s_shared
{
	t_arg				arg;
	int					*is_dead;
	pthread_mutex_t		*dead;
	pthread_mutex_t		*write_protect;
}	t_shared;

typedef struct s_philo
{
	int					balise;
	int					index;
	int					count;
	int					last_meal;
	t_shared			*shared;
	pthread_t			thread;
	struct timeval		tmstp;
	pthread_mutex_t		fork;
	pthread_mutex_t		count_protect;
	struct s_philo		*next;
}	t_philo;

/*------------------------------FUNCTION_C------------------------------------*/

int			ft_strlen(char *str);
int			get_timestamp(struct timeval start);
int			ft_atoi(char *str);
void		ft_error(char *str);
int			check_main(int ac, char **av);
/*------------------------------LISTE_C---------------------------------------*/

void		set_philo(t_philo *philo, int index, struct timeval time,
				t_shared *s);
void		balised(t_philo *balise, t_philo *start);
t_shared	*set_shared(t_arg arg);
t_philo		*set_list(int size, t_shared *shared);

/*------------------------------MONITORING_C----------------------------------*/

//static t_philo	*check_value(t_philo *philo);
//static int	monitoring_eat(t_philo *philo);
void		monitoring(t_philo *philo);

/*------------------------------PHILOSOPHER_C---------------------------------*/

//static void	create_thread(t_philo *philo);
//static void	exit_thread(t_philo *philo);
void		philosopher(t_arg arg);

/*------------------------------PROTECT_C-------------------------------------*/

void		protect_write(t_philo *philo, char *str);
int			protect_check(t_philo *philo);
void		lock(t_philo *philo);
void		unlock(t_philo *philo);

/*------------------------------ROUTINE_C-------------------------------------*/

void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		*routine(void *philo);

#endif
