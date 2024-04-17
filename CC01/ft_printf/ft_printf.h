#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_format
{
	int	left_justify;
	int	p;
	int	s;
	int	zero_padding;
	int	alternative_form;
	int	width;
	int	pre;
}	t_format;

char		*ft_converthexa_ptr(unsigned long long nb);
char		*ft_put_hexa(unsigned int nb, char c);
int			ft_len_hexaptr(unsigned long long nb);
int			ft_lennbr(int nbr, t_format info);
int			ft_lenunbr(unsigned int result);
int			ft_nullpointer(t_format info);
int			ft_printdecimal(va_list args, t_format info);
int			ft_printf(const char *format, ...);
int			ft_printpointer(va_list args, t_format info);
int			ft_printstr(va_list args, t_format info);
int			ft_print_udecimal(va_list args, t_format info);
int			ft_printhexa(va_list args, char c, t_format info);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putstr_reverse(char *str);
int			ft_putnbr(int nb);
int			ft_specifier(const char **format, va_list args);
int			is_specifier(char c);
int			print_and_pad_left(char *str, int real_prec, int padding);
int			print_and_pad_right(int padding, char *str, int real_prec);
int			print_prefix2(int prefix_length, char c);
int			print_prefix_and_pointer(char *pointer_str);
int			prepare_string(va_list args, t_format info, char **str);
t_format	init_format(void);
t_format	parse_format(const char **format);

#endif
