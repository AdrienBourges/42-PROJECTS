NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/

SRC_1 = srcs/push_swap.c
SRC_2 = srcs/ft_algo.c \
        srcs/ft_linked_list.c \
        srcs/ft_movements.c \
		srcs/ft_movements2.c \
		srcs/ft_algo2.c \
	  	srcs/ft_algo4.c \
	   	srcs/ft_algo6.c \
		srcs/ft_algo3.c \
	   	srcs/ft_algo5.c \
	   	srcs/ft_free_exit.c 

OBJ_1 = $(SRC_1:srcs/%.c=$(OBJ_DIR)%.o)
OBJ_2 = $(SRC_2:srcs/%.c=$(OBJ_DIR)%.o)

INCLUDE = -I includes -L ./libft -lft

# Rule to compile .c files into .o files
$(OBJ_DIR)%.o: srcs/%.c includes/ft_pushswap.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

# Rule to create the main executable
$(NAME): $(OBJ_1) $(OBJ_2)
	make -C $(LIBFTDIR)
	$(CC) $(FLAGS) $(OBJ_1) $(OBJ_2) -o $(NAME) $(INCLUDE)

# Rule to build the main target
all: $(NAME)

# Rule to clean object files and executables
clean:
	$(RM) $(OBJ_1) $(OBJ_2)
	$(RM) -r $(OBJ_DIR)
	@cd $(LIBFTDIR) && $(MAKE) clean

# Rule to perform a full clean, including executables
fclean: clean
	$(RM) $(NAME)
	@cd $(LIBFTDIR) && $(MAKE) fclean

# Rule to rebuild everything
re: fclean all

.PHONY: all clean fclean re

