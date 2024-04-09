#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

void ft_putchar(char c);
void ft_putstr(char *str);
int ft_printf(const char *format, ...);
void ft_specifier(char c, va_list args);



#endif
