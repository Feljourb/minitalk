/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:32:12 by feljourb          #+#    #+#             */
/*   Updated: 2023/12/30 16:38:33 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *len)
{
	if (nb == INT_MIN)
	{
		write (1, "-2147483648", 11);
		*len += 11;
	}
	else if (nb < 0)
	{
		*len += ft_putchar('-');
		nb = -nb;
		ft_putnbr(nb, len);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	else if (nb >= 0 && nb <= 9)
	{
		*len += ft_putchar(nb + '0');
	}
}
