/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:48:52 by vifontai          #+#    #+#             */
/*   Updated: 2022/01/26 19:18:13 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

/*
** j = (av[2][i] & (1 << bitshift));
** here we will compare the char with 1
** 1 -> 00000001 and then we will shift to the left to make our int bigger
** than 0 or not so it can know wether it has to send sigusr1 or sigusr2
** usleep just in let the signals go
*/

/*
** to check if there is no char and it's only numbers
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	check_params(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		printf("Wrong param, it should be ./client [PID] [Your sentence]\n");
		exit (1);
	}
	if (av[1][0] == '\0')
	{
		printf("Please check the PID, it's not the right one\n");
		exit(1);
	}
	while (av[1][i])
	{
		if ((!(ft_isdigit(av[1][i])) || atoi(av[1]) == 0))
		{
			printf("Please only numbers and 0 only is not allowed\n");
			exit(1);
		}
		i++;
	}
}

void	send_signal(int pid, char **av)
{
	int	i;
	int	j;
	int	bitshift;

	j = 0;
	i = 0;
	while (1)
	{
		bitshift = 7;
		while (bitshift >= 0)
		{
			j = (av[2][i] & (1 << bitshift--));
			if (j > 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit (1);
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					exit (1);
			usleep(100);
		}
		if (av[2][i++] == '\0')
			break ;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	check_params(argc, argv);
	pid = atoi(argv[1]);
	send_signal(pid, argv);
	return (0);
}
