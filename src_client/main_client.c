/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:52:02 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/17 17:45:35 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// SIGNAL GESTION
static void	sig_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message received 📩​\n");
}

//
static void	set_signal_handler(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = &sig_handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		ft_printf("Error with signal reception\n");
	sigaction(SIGUSR2, &act, NULL);
}

// SEND THE MESSAGE
static void	send_char(int c, int pid)
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

//
static void	send_message(char *message, int pid_server)
{
	int		i;
	char	*pid_client;

	i = 0;
	pid_client = ft_itoa(getpid());
	while (pid_client[i])
	{
		send_char(pid_client[i], pid_server);
		i++;
	}
	send_char('\0', pid_server);
	free(pid_client);
	i = 0;
	while (message[i])
	{
		send_char(message[i], pid_server);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid_server;
	char	*message;

	if (argc != 3)
		return (ft_printf("USE AS : ./client <PID_SERVER> <MESSAGE>\n"), 0);
	pid_server = ft_atoi(argv[1]);
	if (pid_server <= 0 || pid_server > 2147483647)
		return (ft_printf("Use a valid PID\n"), 0);
	message = ft_strdup(argv[2]);
	send_message(message, pid_server);
	set_signal_handler();
	send_char('\0', pid_server);
	free(message);
}
