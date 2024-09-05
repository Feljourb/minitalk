/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:45:54 by feljourb          #+#    #+#             */
/*   Updated: 2023/12/31 13:53:36 by feljourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(char c, va_list args, int *len)
{
	if (c == '%')
		*len += ft_putchar('%');
	else if (c == 'c')
		*len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		*len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (c == 'u')
		ft_putunbr(va_arg(args, unsigned int), len);
	else if (c == 'x')
		ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef", len);
	else if (c == 'X')
		ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF", len);
	else if (c == 'p')
	{
		*len += ft_putstr("0x");
		ft_puthexa(va_arg(args, unsigned long), "0123456789abcdef", len);
	}
	else
		*len += ft_putchar(c);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				break ;
			ft_format(str[i], args, &len);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
