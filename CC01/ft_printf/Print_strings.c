#include "ft_printf.h"

int	print_and_pad_left(char *str, int real_prec, int padding)
{
	int	result;

	result = 0;
	write(1, str, real_prec);
	result += real_prec;
	while (padding-- > 0)
		result += ft_putchar(' ');
	return (result);
}

int	print_and_pad_right(int padding, char *str, int real_prec)
{
	int	result;

	result = 0;
	while (padding-- > 0)
		result += ft_putchar(' ');
	write(1, str, real_prec);
	result += real_prec;
	return (result);
}

int	prepare_string(va_list args, t_format info, char **str)
{
	int	len;

	*str = va_arg(args, char *);
	if (!*str && (info.pre == -1 || info.pre >= 6))
	{
		*str = "(null)";
		info.pre = -1;
	}
	else if (!*str)
		*str = "";
	len = ft_strlen(*str);
	return (len);
}

int	ft_printstr(va_list args, t_format info)
{
	char	*str;
	int		len;
	int		real_prec;
	int		padding;
	int		result;

	len = prepare_string(args, info, &str);
	real_prec = info.pre;
	if (info.pre < 0 || info.pre > len)
		real_prec = len;
	padding = 0;
	if (info.width > real_prec)
		padding = info.width - real_prec;
	result = 0;
	if (info.left_justify)
		result = print_and_pad_left(str, real_prec, padding);
	else
		result = print_and_pad_right(padding, str, real_prec);
	return (result);
}
