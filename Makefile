# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by noalexan          #+#    #+#              #
#    Updated: 2022/03/31 11:04:58 by noalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

NAME	= libftprintf.a

SRCS	=	ft_printf.c \
			utils.c \

OBJS	= $(SRCS:.c=.o)

RM		= rm -rf
AR		= ar rcs

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
