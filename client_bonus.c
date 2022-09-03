/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:25:01 by duzun             #+#    #+#             */
/*   Updated: 2022/09/03 04:27:50 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_sender(int pid, char i)
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
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("\033[31;1mWrong Format.\n\033[32mIncorrect entry!\n\
Please enter transaction ID and message.\033[0m\n", 1);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_sender(pid, argv[2][i]);
		i++;
	}
	return (0);
}
