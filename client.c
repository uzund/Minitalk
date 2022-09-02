/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:05:53 by duzun             #+#    #+#             */
/*   Updated: 2022/09/03 00:19:44 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	*encoder(char c)
{
	int	*train;
	int	i;
	int	decimal;

	train = malloc(sizeof(*train) * 8);
	if (!train)
		exit(EXIT_FAILURE);
	i = 7;
	decimal = (int)c;
	while (decimal)
	{
		train[i--] = decimal % 2;
		decimal /= 2;
	}
	while (i > -1)
	train[i--] = 0; 
	return (train); 
}

void	sender(int *train, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (train[i] == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "Posts did not reach the server.\n", 33);
				exit(EXIT_FAILURE);
			}
		}
		else if (train[i] == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "Posts did not reach the server.\n", 33);
				exit(EXIT_FAILURE);
			}
		}
		i++;
		usleep(101);
	}
	free(train);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		*train;
	int		i;

	i = 0;
	if (argc != 3)
	{
		write(1, "Incorrect entry!\n\
Please enter transaction ID and message.\n", 58);
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	while (argv[2][i])
	{
		train = encoder(argv[2][i]);
		sender(train, pid);
		i++;
	}
	return (0);
}
