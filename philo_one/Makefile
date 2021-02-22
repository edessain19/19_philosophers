NAME = philo_one
SRCS = main.c \
		srcs/ft_fill_the_struct.c \
		srcs/tools.c \
		srcs/ft_action.c \
		srcs/ft_libft.c \
		srcs/ft_itoa.c \
		srcs/ft_print.c

OBJS = $(SRCS:.c=.o)

INCLUDE = include/philo.h
CC = gcc -Wall -Werror -Wextra
RM = rm -f

all:		${NAME}

$(NAME):	$(OBJS)
			$(CC) -I./ $(OBJS) -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
