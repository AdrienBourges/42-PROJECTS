#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int i;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_specifier(format[i], args);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (i);
}

#include <stdio.h>

int main()
{
	ft_printf("abcd%s", "hello");
	printf("\n");
	printf("%p", "hello");
}	

