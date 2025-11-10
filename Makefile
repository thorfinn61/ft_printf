# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 08:24:21 by elsahin           #+#    #+#              #
#    Updated: 2025/11/10 08:24:26 by elsahin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = ft_printf.c utils.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re