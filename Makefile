# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by noalexan          #+#    #+#              #
#    Updated: 2022/05/31 14:47:45 by noalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
CFLAGS	:= -Werror -Wextra -Wall

NAME	:= printf.a

SRCS	:=	ft_printf.c \
			ft_printf_utils.c \

OBJS	:= $(SRCS:.c=.o)

GREEN	:= "\033[0m\033[1;32m"
CYAN	:= "\033[0m\033[1;36m"
YELLOW	:= "\033[0m\033[1;33m\033[3;33m"
RESET	:= "\033[0m"

RM		:= rm -rf
AR		:= ar rcs

.c.o:
	@printf $(GREEN)"\r\033[KCompiling printf... "$(YELLOW)"<$<> "$(RESET)"⏳"
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME): $(OBJS)
	@printf $(CYAN)"\r\033[KCompiling '$(NAME)'... "$(RESET)"⏳"
	@$(AR) $(NAME) $(OBJS)
	@printf $(GREEN)"\r\033[KPrintf compiled succesfully ✅\n"$(RESET)

all: $(NAME)

clean:
	@printf $(CYAN)"\r\033[KErasing printf... "$(RESET)"⏳"
	@$(RM) $(OBJS)

fclean: clean
	@printf $(CYAN)"\r\033[KErasing $(NAME)... "$(RESET)"⏳"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
