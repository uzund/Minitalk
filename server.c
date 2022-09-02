/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:05:40 by duzun             #+#    #+#             */
/*   Updated: 2022/09/02 23:52:03 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	decoder(int *train)
{
	int	i;
	int	n;
	int	result;

	i = 0;
	n = 7;
	result = 0;
	while (i < 8)
	{
		result += (train[i] * pow(2, n));
		i++;
		n--;
	}
	return ((char)result);
}

void	handler(int signal)
{
	static int	i;
	char		c;
	static int	train[8];

	if (signal == SIGUSR1)
		train[i++] = 1;
	else if (signal == SIGUSR2)
		train[i++] = 0;
	if (i == 8)
	{
		c = decoder(train);
		write(1, &c, 1);
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("pid: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
}