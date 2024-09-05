/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:48:33 by feljourb          #+#    #+#             */
/*   Updated: 2023/12/31 11:59:26 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned long i, char *s, int *len)
{
	if (i >= 16)
	{
		ft_puthexa(i / 16, s, len);
		ft_puthexa(i % 16, s, len);
	}
	else
		*len += ft_putchar(s[i]);
}
