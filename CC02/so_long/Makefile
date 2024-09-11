# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -lm
LIBFT = libft/libft.a

# Directories
SRCDIR = srcs
INCDIR = includes
OBJDIR = obj
LIBFTDIR = libft

# Sources and objects
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Name of the executable
NAME = so_long

# Includes and library paths
INCLUDES = -I$(INCDIR) -Imlx -I$(LIBFTDIR)

# Rules

# Create object directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compile the program
all: $(OBJDIR) $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

# Clean object files and executable
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

# Recompile everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re

