NAME = libftprintf.a

SRCS = ft_printf.c \
	   parse_and_flags.c \
	   Specifier_conversion.c \
		
CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

MAKE = make

all =   
		$(MAKE) -C  ./libft
		$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(OBJS) 
	ar rcs $(NAME) $(OBJS)

.PHONY: all clean fclean re 
