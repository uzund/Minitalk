/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:05:40 by duzun             #+#    #+#             */
/*   Updated: 2022/09/02 23:32:13 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
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