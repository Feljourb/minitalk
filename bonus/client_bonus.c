/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:48:39 by feljourb          #+#    #+#             */
/*   Updated: 2024/09/03 16:33:56 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void handler(int signum)
{
	if(signum == SIGUSR1)
		ft_printf("Message recu\n");
}

void envoyer_message(int pid, char c)
{
	int i = 7;
	while(i >= 0)
	{
		if((c >> i) & 1)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		usleep(250);
		i--;
	}	
}

int	main(int ac, char **av)
{	
	struct sigaction	sa;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	 ft_printf("PID du serveur : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	if (ac != 3)
	{
		ft_printf("seulement 3 arguments entrés\n");
		exit(1);
	}
	int pid = ft_atoi(av[1]);
	char *message = av[2];
	int i = 0;
	while (message[i])
	{
		envoyer_message(pid, message[i]);
		i++;
	}
	envoyer_message(pid, '\0');
	return(0);
}
