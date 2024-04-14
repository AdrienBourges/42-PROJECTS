#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_format
{
    int left_justify;
    int plus;
    int space;
    int zero_padding;
    int alternative_form;
    int width;
    int precision;
} t_format;

int ft_putchar(char c);
int ft_putstr(char *str);
int ft_printf(const char *format, ...);
int ft_specifier(const char **format, va_list args);
t_format parse_format(const char **format);
int is_specifier(char c);
size_t ft_strlen(const char *s);



#endif
