/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifontai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:48:34 by vifontai          #+#    #+#             */
/*   Updated: 2022/01/26 19:15:08 by vifontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 ** 0x80 is equal to 128 (10000000)
 ** 0xFF is equal to 255 (11111111)
 ** then we will shift to the left to have either 1 or 0 to compare each time 
 ** | -> or operator (1 1 = 1 1 0 = 1 0 1 = 1 0 0 = 0)
 ** ^ -> xor operator (1 1 = 0 1 0 = 1 0 1 = 1 0 0 = 0)
 ** The signal will modify the byte in 1 or 0 depending on the operation
 ** SIGUSR1 will be used for "1" & SIGUSR2 "0"
 ** pause(); it pauses the system untill a next signal is sent
 */

void	signal_sigusr(int signum)
{
	static char	c = 0xFF;
	static int	bits = 0;
	static char	buf[1000];
	static int	len;

	if (signum == SIGUSR1)
		c |= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c ^= 0x80 >> bits;
	bits++;
	if (bits == 8)
	{
		buf[len++] = c;
		if (c == '\0' || len >= 1000)
		{
			write(1, buf, len - (c == '\0'));
			len = 0;
		}
		bits = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	printf("Please find the pid: %d\n", getpid());
	signal(SIGUSR1, signal_sigusr);
	signal(SIGUSR2, signal_sigusr);
	while (1)
		pause();
}
