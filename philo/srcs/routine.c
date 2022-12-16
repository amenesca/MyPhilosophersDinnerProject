#include "../includes/philosophers.h"

void	*routine(void *argv)
{
	t_philo	*philo;

	philo = argv;
	philo->nbr_ate = 0;
	if (philo->ph_id % 2)
		usleep(philo->data_ph->time_eat * 1000);
	while (!philo->data_ph->finish)
	{
		get_fork(philo);
		is_eating(philo);
		is_sleep(philo);
		msg(philo, "is thinking");
	}
	return (0);
}

void	*monitor(void *argv)
{
	t_philo			*philo;
	long long		ms;
	struct timeval	time_now;
	unsigned long	time_of_die;

	philo = argv;
	while (!philo->data_ph->finish)
	{
		pthread_mutex_lock(&philo->check_mutex);
		pthread_mutex_lock(&philo->data_ph->end_mutex);
		gettimeofday(&time_now, NULL);
		ms = time_ms(time_now) - time_ms(philo->last_eat);
		gettimeofday(&time_now, NULL);
		time_of_die = time_ms(time_now) - time_ms(philo->data_ph->create_at);
		if (ms > philo->data_ph->time_die && philo->data_ph->finish == 0)
		{
			printf("%lums\t%d\t %s\n", time_of_die, philo->ph_id, "died");
			philo->data_ph->finish = 1;
		}
		pthread_mutex_unlock(&philo->data_ph->end_mutex);
		pthread_mutex_unlock(&philo->check_mutex);
		usleep(100);
	}
	return (0);
}

void	msg(t_philo *philo, char *str)
{
	long long		ms;
	struct timeval	time_now;

	pthread_mutex_lock(&philo->data_ph->end_mutex);
	gettimeofday(&time_now, NULL);
	ms = time_ms(time_now) - time_ms(philo->data_ph->create_at);
	if (!philo->data_ph->finish)
		printf("%lldms\t%d\t %s\n", ms, philo->ph_id, str);
	pthread_mutex_unlock(&philo->data_ph->end_mutex);
}