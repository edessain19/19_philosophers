# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edessain <edessain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 20:05:16 by edessain          #+#    #+#              #
#    Updated: 2021/03/02 14:47:46 by edessain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
		srcs/ft_routine.c \
		srcs/utils.c \
		srcs/print.c \
		srcs/ft_error.c \
		srcs/libft.c \
		srcs/libft2.c
		
OBJS = $(SRCS:%.c=%.o)

NAME = philo_one

CFLAGS = -g -Wall -Wextra -Werror -pthread

all:		$(NAME)

$(NAME):	$(OBJS)
			gcc $(CFLAGS) -o $(NAME) $(OBJS)

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
