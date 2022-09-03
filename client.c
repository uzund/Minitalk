/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:05:53 by duzun             #+#    #+#             */
/*   Updated: 2022/09/03 03:21:17 by duzun            ###   ########.fr       */
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

//void	sender(char c, pid_t pid)
//{
//	int	i;

//	i = 0x80;
//	while (i)
//	{
//		if (c == 1)
//		{
//			if (kill(pid, SIGUSR1) == -1)
//			{
//				write(1, "Posts did not reach the server.\n", 33);
//				exit(EXIT_FAILURE);
//			}
//		}
//		else if (c == 0)
//		{
//			if (kill(pid, SIGUSR2) == -1)
//			{
//				write(1, "Posts did not reach the server.\n", 33);
//				exit(EXIT_FAILURE);
//			}
//		}
//		//if (kill(pid, c & i ? SIGUSR1 : SIGUSR2) == -1)
//		//{
//		//	write(2, "Posts did not reach the server.\n", 33);
//		//	exit(EXIT_FAILURE);
//		//}
//		i >>= 1;
//		usleep(100);
//	}
//}
//void	sender(int *train, pid_t pid)
//{
//	int	i;

//	i = 0;
//	while (i < 8)
//	{
//		if (train[i] == 1)
//		{
//			if (kill(pid, SIGUSR1) == -1)
//			{
//				write(1, "Posts did not reach the server.\n", 33);
//				exit(EXIT_FAILURE);
//			}
//		}
//		else if (train[i] == 0)
//		{
//			if (kill(pid, SIGUSR2) == -1)
//			{
//				write(1, "Posts did not reach the server.\n", 33);
//				exit(EXIT_FAILURE);
//			}
//		}
//		i++;
//		usleep(101);
//	}
//	free(train);
//}

void	sender(int pid, char i)
{	
	int	bit;

	bit = 0;
	while (bit < 8)	
	{		
		if ((i & (0x01 << bit)) != 0)			
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(123);	
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		*train;
	int		i;

	i = 0;
	if (argc != 3)
	{
		write(1, "\033[31mWrong Format.\n\033[32mIncorrect entry!\n\
Please enter transaction ID and message.\033[0m\n", 86);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		//train = encoder(argv[2][i]);
		sender(pid, argv[2][i]);
		i++;
	}
	return (0);
}
