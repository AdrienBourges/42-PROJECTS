#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	result;

	result = 0;
	while (*str)
		result += ft_putchar(*str++);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	result = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			result += ft_specifier(&format, args);
		}
		else
			result += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (result);
}
