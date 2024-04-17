#include "ft_printf.h"

int	ft_put_udecimal(unsigned int nb, int fd)
{
	int	result;

	result = 0;
	if (nb > 9)
	{
		result += ft_put_udecimal(nb / 10, fd);
	}
	result += ft_putchar((nb % 10) + 48);
	return (result);
}

int	ft_lenunbr_u(unsigned int result, t_format info)
{
	int	len;

	len = 0;
	if (result == 0 && info.pre == 0)
		return (0);
	else if (result == 0)
		return (1);
	while (result > 0)
	{
		result /= 10;
		len++;
	}
	return (len);
}

int	print_padding_u(int padding, t_format info)
{
	int	chars_nb;
	int	temp;

	temp = padding;
	chars_nb = 0;
	if (!info.left_justify && (info.pre >= 0 || !info.zero_padding))
	{
		while (padding-- > 0)
			chars_nb += ft_putchar(' ');
		padding = temp;
	}
	if (!info.left_justify && info.zero_padding && info.pre < 0)
	{
		while (padding-- > 0)
			chars_nb += ft_putchar('0');
		padding = temp;
	}
	return (chars_nb);
}

int	ft_print_udecimal(va_list args, t_format info)
{
	unsigned int	result;
	int				preci;
	int				total_padding;
	int				chars_nb;

	chars_nb = 0;
	result = va_arg(args, unsigned int);
	preci = 0;
	if (info.pre > ft_lenunbr_u(result, info))
		preci = info.pre - ft_lenunbr_u(result, info);
	total_padding = info.width - (preci + ft_lenunbr_u(result, info));
	chars_nb += print_padding_u(total_padding, info);
	if (result != 0 || (info.pre != 0 && result == 0))
	{
		while (preci-- > 0)
			chars_nb += ft_putchar('0');
		chars_nb += ft_put_udecimal(result, 1);
	}
	if (info.left_justify)
	{
		while (total_padding-- > 0)
			chars_nb += ft_putchar(' ');
	}
	return (chars_nb);
}
