/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:47:16 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/17 13:05:09 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_octet;

void	sig_handler(int signal)
{
	static int	i = 8;

	i--;
	if (signal == SIGUSR1)
		g_octet |= (1 << i);
	if (i == 0)
	{
		if (g_octet == '\0')
		{
			//ft_printf("\nMessage received!\n");
		}
		else
			write(1, (void *)&g_octet, 1);
		i = 8;
		g_octet = 0;
	}
}

void	set_signal_handler(void)
{
	struct sigaction	act;

	bzero(&act, sizeof(act));
	act.sa_handler = &sig_handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		ft_printf("Error with signal reception\n");
	sigaction(SIGUSR2, &act, NULL);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	set_signal_handler();
	while (1)
		continue ;
}
