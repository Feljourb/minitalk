/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:48:39 by feljourb          #+#    #+#             */
/*   Updated: 2024/08/31 14:38:09 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void envoyer_message(int pid, char c)
{
	int i = 7;
	while(i >= 0)
	{
		if((c >> i) & 1)
		{
			kill(pid, SIGUSR2);
			ft_printf("le message de SIGUSR2 pour le bit %d\n", i);
		}
		else
		{
			kill(pid, SIGUSR1);
			ft_printf("le message de SIGUSR1 POUR LE BIT %d\n", i);
		}
		usleep(150);
		i--;
	}
    pause();
	
}

int	main(int ac, char **av)
{
	if(ac != 3)
	{
		ft_printf("seulement 3 arguments entrés\n");
		exit(1);
	}
	int pid = ft_atoi(av[1]);
	char *message = av[2];
	int i = 0;
	while(message[i])
	{
		envoyer_message(pid, message[i]);
		i++;
	}

	return(0);
}
