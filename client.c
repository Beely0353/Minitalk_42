/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:11:07 by baroun            #+#    #+#             */
/*   Updated: 2022/03/08 17:33:08 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_to_server(pid_t pid, char str)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((str >> i) & 1)
		{
			usleep(100);
			kill(pid, SIGUSR1);
		}
		else
		{
			usleep(100);
			kill(pid, SIGUSR2);
		}
		usleep(50);
		i++;
	}
}

int	ft_error(int argc, char *argv)
{
	int	a;

	a = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Need 2 args : PID & string\n", 1);
		return (0);
	}
	while (argv[a])
	{
		if (!ft_isdigit(argv[a]))
		{
			ft_putstr_fd("PID must be a number\n", 1);
			return (0);
		}
		a++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	a;

	if (ft_error(argc, argv[1]) == 0)
		return (0);
	a = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][a])
	{
		send_to_server(pid, argv[2][a]);
		a++;
	}
	return (0);
}
