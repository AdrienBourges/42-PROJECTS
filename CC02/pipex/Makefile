# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = srcs
INCDIR = includes
OBJDIR = obj

# Files and objects
SRCFILES = $(wildcard $(SRCDIR)/*.c)
OBJFILES = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCFILES))
NAME = pipex

# Default target (build the program)
all: $(NAME)

# Make sure object directory exists
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Rule to create object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Rule to compile the program
$(NAME): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(NAME)

# Clean object files
clean:
	rm -rf $(OBJDIR)

# Clean all files (object files and the compiled program)
fclean: clean
	rm -f $(NAME)

# Recompile the project
re: fclean $(NAME)

# Phony targets
.PHONY: all clean fclean re

