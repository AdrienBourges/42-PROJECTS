NAME = ft_display_file

SRC = ft_display_file.c

OBJS = ft_display_file.o

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
