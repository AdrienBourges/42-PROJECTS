NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

SRCS 			=	ft_printf.c parse_and_flags.c Specifier_conversion.c Print_strings.c Print_pointers.c Print_decimals.c Print_hexas.c Print_unsigned.c printf_utils.c printf_utils2.c

OBJ_DIR			=	obj
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				all

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS)
				cp	$(LIBFT) $(NAME)
					ar -rcs $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					make -C $(LIBFT_PATH) clean
					rm -rf $(OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					rm -rf $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re libft
