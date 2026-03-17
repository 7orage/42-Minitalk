/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:52:02 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/17 13:11:51 by lheteau          ###   ########.fr       */
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
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int		pid_server;
	char	*message;
	int		i;

	i = 0;
	(void)argv;
	if (argc != 3)
		return (ft_printf("USE AS : ./client <PID_SERVER> <MESSAGE>\n"), 0);
	pid_server = ft_atoi(argv[1]);
	if (pid_server <= 0 || pid_server > 2147483647)
		return (ft_printf("Use a valid PID\n"), 0);
	message = ft_strdup(argv[2]);


	while (message[i])
	{
		send_char(message[i], pid_server);
		i++;
	}
	send_char('\0', pid_server);
	free(message);
}
