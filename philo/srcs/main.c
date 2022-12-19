/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:23:20 by amenesca          #+#    #+#             */
/*   Updated: 2022/12/19 18:19:44 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	memset(&data, 0, sizeof(data));
	if (argc != 5 && argc != 6)
	{
		printf("ERROR: philo accepts only 4 or 5 arguments.\n");
		return (1);
	}
	if (threat_args(argc, argv, &data) == -1)
	{
		printf("ERROR: philo accepts only ints as inputs.\n");
		return (2);
	}
	init_mutex(&data);
	init_threads(&data);
	wait_release_philo(&data);
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_data) * data->nbr_phil);
	data->th = malloc(sizeof(pthread_t) * data->nbr_phil);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_phil);
	pthread_mutex_init(&data->end_mutex, NULL);
	while (i < data->nbr_phil)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->philos[i].check_mutex, NULL);
		i++;
	}
	return (0);
}

void	init_threads(t_data *data)
{
	int			i;
	pthread_t	sensei;

	i = 0;
	gettimeofday(&data->create_at, NULL);
	while (i < data->nbr_phil)
	{
		gettimeofday(&data->philos[i].last_eat, NULL);
		data->philos[i].ph_id = i + 1;
		data->philos[i].data_ph = data;
		pthread_create(&data->th[i], NULL, routine, &data->philos[i]);
		pthread_create(&sensei, NULL, monitor, &data->philos[i]);
		i++;
	}
	if (data->nbr_must_eat != 0)
		eat_enough(data);
}

void	*eat_enough(void *data)
{
	t_data	*temp;

	temp = data;
	while (temp->finish == 0)
	{
		pthread_mutex_lock(&temp->end_mutex);
		if (temp->n_philos_end_eat == temp->nbr_phil)
			temp->finish = 1;
		pthread_mutex_unlock(&temp->end_mutex);
	}
	return (NULL);
}
