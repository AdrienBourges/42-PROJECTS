#include "ft_printf.h"

void ft_printstr(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	ft_putstr(str);
}

void ft_printchar(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	ft_putchar(c);
}

void ft_printpointer(va_list args)
{


void ft_specifier(char c, va_list args)
{
	if (c == 's')
		ft_printstr(args);
	else if (c == 'c')
		ft_printchar(args);
	else if (c == 'p')
		ft_printpointer(args);
/*	else if (c == 'd')
	else if (c == 'i')
	else if (c == 'u')
	else if (c == 'x')
	else if (c == 'X')
	else if (c == '%')

*/
}
