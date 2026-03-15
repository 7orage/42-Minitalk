/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:52:02 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/15 19:59:09 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int c, int pid)
{
	int		bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c & (1 << bit)))
		{
			kill(pid, SIGUSR1);
			ft_printf("il y a un 1 \n");
		}
		else
		{
			kill(pid, SIGUSR2);
			ft_printf("il y a un 0 \n");
		}
		usleep(100);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;
	int		i;

	i = 0;
	(void)argv;
	if (argc != 3)
		ft_printf("USE AS : ./client <PID_SERVER> <MESSAGE>\n");
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	message = ft_strdup(argv[2]);
	ft_printf("message %s\n", message);
	while (message[i])
	{
		send_char(message[i], pid);
		ft_printf("autre char \n");
		i++;
		usleep(100);
	}
	send_char('\0', pid);
	free(message);
}
