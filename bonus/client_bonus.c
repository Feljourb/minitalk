/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:48:39 by feljourb          #+#    #+#             */
/*   Updated: 2024/09/04 00:09:41 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Message reçu\n");
}

void	envoyer_message(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;
	char				*message;
	int					i;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	if (ac != 3)
	{
		ft_printf("seulement 3 arguments entrés\n");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	message = av[2];
	i = 0;
	while (message[i])
	{
		envoyer_message(pid, message[i]);
		i++;
	}
	envoyer_message(pid, '\0');
	return (0);
}
