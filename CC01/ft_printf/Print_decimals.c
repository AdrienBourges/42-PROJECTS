#include "ft_printf.h"

int	print_padding(int pad, char pad_char)
{
	int		chars_nb;

	chars_nb = 0;
	while (pad-- > 0)
		chars_nb += ft_putchar(pad_char);
	return (chars_nb);
}

int	print_sign(int result, t_format info)
{
	if (result < 0)
		return (ft_putchar('-'));
	else if (info.p)
		return (ft_putchar('+'));
	else if (info.s)
		return (ft_putchar(' '));
	return (0);
}

int	print_number(int result, int preci)
{
	int	chars_nb;

	chars_nb = 0;
	while (preci-- > 0)
		chars_nb += ft_putchar('0');
	if (result == -2147483648)
		chars_nb += ft_putstr("2147483648");
	else
		chars_nb += ft_putnbr(result);
	return (chars_nb);
}

int	ft_sign(int result, t_format info)
{
	if (result < 0 || info.p || info.s)
		return (1);
	return (0);
}

int	ft_printdecimal(va_list args, t_format info)
{
	int	result;
	int	len;
	int	preci;
	int	pad;
	int	chars_nb;

	result = va_arg(args, int);
	len = ft_lennbr(result, info);
	if (result == -2147483648)
		len = 10;
	preci = 0;
	if (info.pre > len)
		preci = info.pre - len;
	pad = info.width - (preci + len + ft_sign(result, info));
	chars_nb = 0;
	if (!info.left_justify && (info.pre >= 0 || !info.zero_padding))
		chars_nb += print_padding(pad, ' ');
	chars_nb += print_sign(result, info);
	if (!info.left_justify && info.zero_padding && info.pre < 0)
		chars_nb += print_padding(pad, '0');
	if (result != 0 || info.pre != 0)
		chars_nb += print_number(result, preci);
	if (info.left_justify)
		chars_nb += print_padding(pad, ' ');
	return (chars_nb);
}
