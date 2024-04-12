NAME = libftprintf.a

SRCS = ft_printf.c \
	   parse_and_flags.c \
	   Specifier_conversion.c \
		
CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

MAKE = make

libft :	
	@$(MAKE) -C  ./libft

all :  libft $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
