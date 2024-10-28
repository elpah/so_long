# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eobeng <eobeng@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 15:10:54 by eobeng            #+#    #+#              #
#    Updated: 2024/10/24 18:20:23 by eobeng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for printf

SRCS = ft_printf.c ft_printaddress.c ft_printchar.c ft_printdigit.c \
		ft_printstr.c ft_printudigit.c ft_printhex.c

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

NAME = ft_printf.a

all: $(NAME)


$(NAME):  $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
