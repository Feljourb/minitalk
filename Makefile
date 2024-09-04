# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/24 18:41:11 by feljourb          #+#    #+#              #
#    Updated: 2024/09/03 17:21:11 by feljourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server
NAME_S_BONUS = server_bonus
NAME_C_BONUS = client_bonus

CFLAGS =  -Wall -Wextra -Werror

CC = cc

SRCS_C = client.c utils.c ftprintf/ft_printf.c ftprintf/ft_putchar.c ftprintf/ft_puthexa.c \
		ftprintf/ft_putnbr.c ftprintf/ft_putstr.c ftprintf/ft_putunbr.c
		
SRCS_S = server.c ftprintf/ft_printf.c ftprintf/ft_putchar.c ftprintf/ft_puthexa.c \
		ftprintf/ft_putnbr.c ftprintf/ft_putstr.c ftprintf/ft_putunbr.c
		
SRCS_C_BONUS = bonus/client_bonus.c utils.c ftprintf/ft_printf.c ftprintf/ft_putchar.c ftprintf/ft_puthexa.c \
		ftprintf/ft_putnbr.c ftprintf/ft_putstr.c ftprintf/ft_putunbr.c

SRCS_S_BONUS = bonus/server_bonus.c ftprintf/ft_printf.c ftprintf/ft_putchar.c ftprintf/ft_puthexa.c \
		ftprintf/ft_putnbr.c ftprintf/ft_putstr.c ftprintf/ft_putunbr.c

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