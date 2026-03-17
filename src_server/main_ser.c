/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:47:16 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/17 17:51:46 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_octet;

// UTIL
char	*ft_mini_join(char	*pid, char c)
{
	char	*join;
	int		i;

	i = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(pid) + 2));
	if (pid == NULL)
	{
		join[0] = c;
		join[1] = '\0';
		return (join);
	}
	while (pid[i])
	{
		join[i] = (char)pid[i];
		i++;
	}
	join[i] = c;
	join[i + 1] = '\0';
	return (join);
}

// SIGNAL GESTION
static int	pid_true(char **pid_client)
{
	if (g_octet == '\0')
	{
		kill(ft_atoi(*pid_client), SIGUSR1);
		ft_printf("\n");
		free(*pid_client);
		*pid_client = NULL;
		return (0);
	}
	else
		return (write(1, (void *)&g_octet, 1), 1);
}

//
static void	sig_handler(int signal)
{
	static int	i = 8;
	static char	*pid_client;
	static bool	pid = false;

	i--;
	if (signal == SIGUSR1)
		g_octet |= (1 << i);
	if (i == 0)
	{
		if (pid == true)
		{
			if (pid_true(&pid_client) == 0)
				pid = false;
		}
		else if (pid == false)
		{
			if (g_octet == '\0')
				pid = true;
			else
				pid_client = ft_mini_join(pid_client, g_octet);
		}
		i = 8;
		g_octet = 0;
	}
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

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	set_signal_handler();
	while (1)
		continue ;
}
