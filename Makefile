# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/24 18:41:11 by feljourb          #+#    #+#              #
#    Updated: 2024/08/31 14:25:30 by feljourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server
NAME_S_BONUS = server_bonus
NAME_C_BONUS = client_bonus

CFLAGS =  -Wall -Wextra -Werror

CC = cc

SRCS_C = client.c utils.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_puthexa.c \
		ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/ft_putunbr.c
		
SRCS_S = server.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_puthexa.c \
		ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/ft_putunbr.c
		
SRCS_C_BONUS = bonus/client_bonus.c utils.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_puthexa.c \
		ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/ft_putunbr.c

SRCS_S_BONUS = bonus/server_bonus.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_puthexa.c \
		ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/ft_putunbr.c

OBJS_C = $(SRCS_C:.c=.o)

OBJS_S = $(SRCS_S:.c=.o)

OBJS_C_BONUS = $(SRCS_C_BONUS:.c=.o)

OBJS_S_BONUS = $(SRCS_S_BONUS:.c=.o)



all: $(NAME_C) $(NAME_S) $(NAME_S_BONUS) $(NAME_C_BONUS)

$(NAME_C): $(OBJS_C)
	$(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(CFLAGS) -o $(NAME_S) $(OBJS_S)

$(NAME_S_BONUS) : $(OBJS_S_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_S_BONUS) $(OBJS_S_BONUS)	

$(NAME_C_BONUS) : $(OBJS_C_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_C_BONUS) $(OBJS_C_BONUS)	

clean:
	rm -f $(OBJS_C) $(OBJS_S)
	rm -f $(OBJS_S_BONUS) $(OBJS_C_BONUS)

fclean: clean
	rm -f $(NAME_C) $(NAME_S)
	rm -f $(NAME_S_BONUS) $(NAME_C_BONUS)


re: fclean all

.PHONY: all clean fclean re