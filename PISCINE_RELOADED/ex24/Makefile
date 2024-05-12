NAME = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

OBJS = $(SRCS:srcs/%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADERS = includes

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : srcs/%.c
	$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all
