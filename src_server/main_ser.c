/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:47:16 by lheteau           #+#    #+#             */
/*   Updated: 2026/03/15 20:03:39 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signal)
{
	static char	octet = 0;
	static int	i = 1;

	i++;
	if (signal == SIGUSR1)
		octet |= (1 << i);
	ft_printf("i : %d, octet %u\n", i, octet);
	if (i == 7)
	{
		if (octet == '\0')
			ft_printf("\nMessage received!\n");
		else
		{
			ft_printf("\ncharacter recu %u\n", octet);
			write(1, &octet, 1);
			ft_printf("\n");
		}
		i = 1;
		octet = 0;
	}
}

//int sigaction (int signum, const struct sigaction * act,
//                                 struct sigaction * o_act);

//struct sigaction
//{
//    void    (*sa_handler) (int);
//    sigset_t sa_mask;
//    int      sa_flags;
//
//}; // sigaction

void	set_signal_handler(void)
{
	struct sigaction	act;

	bzero(&act, sizeof(act));
	act.sa_handler = &sig_handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		ft_printf("error\n");
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
	// ft_printf("SIGNAL BIEN RECU\n");
}
