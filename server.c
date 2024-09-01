/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:39:58 by feljourb          #+#    #+#             */
/*   Updated: 2024/08/31 22:09:04 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signum)
{
	static char c = 0;
	static int i = 7;
	if(signum == SIGUSR1)
		c |= (0 << i);
	if(signum == SIGUSR2)
		c |= (1 << i);
	i--;
	while(i < 0)
	{
		ft_printf("%c", c);
		c = 0;
		i = 7;
	}
}


int	main()
{
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	
	if(sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);

    ft_printf("PID du serveur : %d\n", getpid());
    while (1)
    {
        pause();
    }
    return(0);
}
