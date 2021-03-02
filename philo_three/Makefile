NAME = philo_three
SRCS = main.c \
		./srcs/ft_fill_struct.c \
		./srcs/tools.c \
		./srcs/ft_action.c \
		./srcs/ft_libft.c \
		./srcs/ft_itoa.c \
		./srcs/ft_print.c \


OBJS = $(SRCS:.c=.o)

INCLUDE = include/philo_three.h
CC = gcc -g -Wall -Werror -Wextra -pthread 
RM = rm -f

all:		${NAME}

$(NAME):	$(OBJS)
			$(CC) -I./ $(OBJS) -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all