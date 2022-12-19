/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:28:27 by amenesca          #+#    #+#             */
/*   Updated: 2022/12/19 18:31:05 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_philo
{
	int				ph_id;
	int				nbr_ate;
	struct timeval	last_eat;
	int				fork_r;
	int				fork_l;
	int				is_dead;
	pthread_mutex_t	check_mutex;
	struct s_data	*data_ph;
}	t_philo;

typedef struct s_data
{
	int				nbr_phil;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_must_eat;
	int				n_philos_end_eat;
	int				finish;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	*forks;
	pthread_t		*th;
	t_philo			*philos;
	struct timeval	create_at;
}	t_data;

int				threat_args(int argc, char **argv, t_data *data);
int				ft_atoi(const char *str);
int				ft_strisdigit(char *str);
int				init_mutex(t_data *data);
void			init_threads(t_data *data);
int				init_mutex(t_data *data);
void			*eat_enough(void *data);
void			*routine(void *argv);
void			*monitor(void *argv);
void			msg(t_philo *philo, char *str);
void			get_fork(t_philo *philo);
void			is_eating(t_philo *philo);
void			is_sleep(t_philo *philo);
void			short_sleep(unsigned long time, t_philo *philo);
unsigned long	time_ms(struct timeval time);
void			wait_release_philo(t_data *data);

#endif
