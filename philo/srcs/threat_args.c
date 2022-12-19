/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threat_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:15:15 by amenesca          #+#    #+#             */
/*   Updated: 2022/12/19 18:23:44 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	threat_args(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_strisdigit(argv[i]) == 0)
			return (-1);
	}
	data->nbr_phil = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nbr_must_eat = ft_atoi(argv[5]);
	return (0);
}

int	ft_strisdigit(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}
