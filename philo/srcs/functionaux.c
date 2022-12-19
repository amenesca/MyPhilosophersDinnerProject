/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionaux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:14:40 by amenesca          #+#    #+#             */
/*   Updated: 2022/12/19 18:16:34 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

unsigned long	time_ms(struct timeval time)
{
	return ((time.tv_sec * 1000) + time.tv_usec / 1000);
}

static int	check(int sign)
{
	if (sign < 0)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int		res;
	long	sign;
	int		x;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		x = res;
		res = (res * 10) + (*str - '0');
		if (res < x)
			return (check(sign));
		str++;
	}
	return (res * sign);
}

void	short_sleep(unsigned long time, t_philo *philo)
{
	unsigned long	start;
	unsigned long	time_diff;
	unsigned long	before;
	struct timeval	time_before;
	struct timeval	time_now;

	gettimeofday(&time_before, NULL);
	before = time_ms(time_before);
	while (!(philo->data_ph->finish))
	{
		gettimeofday(&time_now, NULL);
		start = time_ms(time_now);
		time_diff = start - before;
		if (time_diff >= time)
			break ;
		usleep(50);
	}
}
