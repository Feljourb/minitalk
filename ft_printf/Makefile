# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 13:24:30 by feljourb          #+#    #+#              #
#    Updated: 2023/12/31 13:24:31 by feljourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc

CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRC = ft_printf.c ft_putchar.c ft_puthexa.c  ft_putstr.c ft_putnbr.c ft_putunbr.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $?

clean:
	rm -f $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: clean re fclean all .c.o
