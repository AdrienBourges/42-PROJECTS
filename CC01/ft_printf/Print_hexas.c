#include "ft_printf.h"

int	ft_precision_and_print(int result, int precision, int padding, char *str)
{
	int	chars_nb;

	chars_nb = 0;
	if (result != 0 || (result == 0 && precision != 0))
	{
		while (padding-- > 0)
			chars_nb += ft_putchar('0');
		chars_nb += ft_putstr_reverse(str);
	}
	return (chars_nb);
}

int	ft_minus(int width, int minus)
{
	int	chars_nb;

	chars_nb = 0;
	if (minus)
	{
		while (width > 0)
		{
			chars_nb += ft_putchar(' ');
			width--;
		}
	}
	return (chars_nb);
}

int	ft_padding(t_format info)
{
	int	chars_nb;

	chars_nb = 0;
	if (!info.left_justify && (info.zero_padding && info.pre < 0))
	{
		while (info.width > 0)
		{
			chars_nb += ft_putchar('0');
			info.width--;
		}
	}
	else if (!info.left_justify)
	{
		while (info.width > 0)
		{
			chars_nb += ft_putchar(' ');
			info.width--;
		}
	}
	return (chars_nb);
}

int	ft_preflen(t_format info, int result)
{
	if (info.alternative_form && result != 0)
		return (2);
	return (0);
}

int	ft_printhexa(va_list args, char c, t_format info)
{
	unsigned int	result;
	char			*str;
	int				prefix_length;
	int				preci;
	int				chars_nb;

	chars_nb = 0;
	result = va_arg(args, unsigned int);
	str = ft_put_hexa(result, c);
	prefix_length = ft_preflen(info, result);
	preci = 0;
	if (info.pre > (int)ft_strlen(str))
		preci = info.pre - ft_strlen(str);
	info.width -= (ft_strlen(str) + preci + prefix_length);
	if (result == 0 && info.pre == 0)
		info.width++;
	chars_nb += ft_padding(info);
	info.width -= chars_nb;
	chars_nb += print_prefix2(prefix_length, c);
	chars_nb += ft_precision_and_print(result, info.pre, preci, str);
	chars_nb += ft_minus(info.width, info.left_justify);
	free(str);
	return (chars_nb);
}
