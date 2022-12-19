/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:15:09 by amenesca          #+#    #+#             */
/*   Updated: 2022/12/19 18:22:22 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	get_fork(t_philo *philo)
{
	philo->fork_l = philo->ph_id - 1;
	philo->fork_r = philo->ph_id % philo->data_ph->nbr_phil;
	pthread_mutex_lock(&philo->data_ph->forks[philo->fork_r]);
	msg(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data_ph->forks[philo->fork_l]);
	msg(philo, "has taken a fork");
}

void	is_eating(t_philo *philo)
{
	long long		ms;
	struct timeval	time_now;

	pthread_mutex_lock(&philo->check_mutex);
	gettimeofday(&time_now, NULL);
	philo->last_eat = time_now;
	ms = time_ms(philo->last_eat) - time_ms(philo->data_ph->create_at);
	pthread_mutex_lock(&philo->data_ph->end_mutex);
	if (!philo->data_ph->finish)
		printf("%llums\t%d\t %s\n", ms, philo->ph_id, "is eating");
	philo->nbr_ate++;
	if (philo->nbr_ate == philo->data_ph->nbr_must_eat)
		philo->data_ph->n_philos_end_eat++;
	pthread_mutex_unlock(&philo->data_ph->end_mutex);
	short_sleep(philo->data_ph->time_eat, philo);
	pthread_mutex_unlock(&philo->data_ph->forks[philo->fork_r]);
	pthread_mutex_unlock(&philo->data_ph->forks[philo->fork_l]);
	pthread_mutex_unlock(&philo->check_mutex);
}

void	is_sleep(t_philo *philo)
{
	msg(philo, "is sleeping");
	short_sleep(philo->data_ph->time_sleep, philo);
}

void	wait_release_philo(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nbr_phil)
	{
		pthread_join(data->th[i], NULL);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->th);
	free(data->philos);
	free(data->forks);
}
