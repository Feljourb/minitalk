/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:30:56 by feljourb          #+#    #+#             */
/*   Updated: 2024/09/03 16:11:10 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	//int	sign;

	i = 0;
	result = 0;
	//sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	// if (str[i] == '-' || str[i] == '+')
	// {
	// 	if (str[i] == '-')
	// 		sign *= -1;
	// 	i++;
	// }
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result <= 0)
	{
		ft_printf("pid error");
		exit(1);
	}
	return (result);
}
