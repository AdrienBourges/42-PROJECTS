#include "ft_printf.h"

int	ft_printchar(va_list args, t_format info)
{
	char	c;
	int		result;

	result = 0;
	c = (char)va_arg(args, int);
	if (info.left_justify == 1)
	{
		result += ft_putchar(c);
		while (info.width - 1 > 0)
		{
			result += ft_putchar(' ');
			info.width--;
		}
		return (result);
	}
	while (info.width - 1 > 0)
	{
		result += ft_putchar(' ');
		info.width--;
	}
	result += ft_putchar(c);
	return (result);
}

int	ft_specifier(const char **format, va_list args)
{
	t_format	info;
	int			result;

	info = parse_format(format);
	if (**format == 's')
		result = ft_printstr(args, info);
	else if (**format == 'c')
		result = ft_printchar(args, info);
	else if (**format == 'p')
		result = ft_printpointer(args, info);
	else if (**format == 'd')
		result = ft_printdecimal(args, info);
	else if (**format == 'i')
		result = ft_printdecimal(args, info);
	else if (**format == 'u')
		result = ft_print_udecimal(args, info);
	else if (**format == 'x' || **format == 'X')
		result = ft_printhexa(args, **format, info);
	else if (**format == '%')
		result = ft_putchar('%');
	return (result);
}
