#include "ft_printf.h"

char	*ft_converthexa_ptr(unsigned long long nb)
{
	char	*hex_base;
	int		i;
	char	*result;

	hex_base = "0123456789abcdef";
	result = malloc(ft_len_hexaptr(nb) + 1);
	if (!result)
		return (NULL);
	if (nb == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	i = 0;
	while (nb > 0)
	{
		result[i++] = hex_base[nb % 16];
		nb = nb / 16;
	}
	result[i] = '\0';
	return (result);
}

int	ft_nullpointer(t_format info)
{
	int	result;

	result = 0;
	if (info.left_justify == 1)
	{
		result += ft_putstr_reverse(")lin(");
		while (info.width - 5 > 0)
		{
			result += ft_putchar(' ');
			info.width--;
		}
		return (result);
	}
	while (info.width - 5 > 0)
	{
		result += ft_putchar(' ');
		info.width--;
	}
	result += ft_putstr_reverse(")lin(");
	return (result);
}

int	print_prefix_and_pointer(char *pointer_str)
{
	int	chars_nb;

	chars_nb = ft_putstr("0x");
	chars_nb += ft_putstr_reverse(pointer_str);
	return (chars_nb);
}

int	pad_spaces(int width, int len_str)
{
	int	chars_nb;
	int	count;

	chars_nb = 0;
	count = width - 2 - len_str;
	while (count > 0)
	{
		chars_nb += ft_putchar(' ');
		count--;
	}
	return (chars_nb);
}

int	ft_printpointer(va_list args, t_format info)
{
	void	*ptr;
	char	*result;
	int		len_str;
	int		chars_nb;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (ft_nullpointer(info));
	result = ft_converthexa_ptr((unsigned long long) ptr);
	len_str = ft_strlen(result);
	chars_nb = 0;
	if (info.left_justify == 1)
	{
		chars_nb += print_prefix_and_pointer(result);
		chars_nb += pad_spaces(info.width, len_str);
	}
	else
	{
		chars_nb += pad_spaces(info.width, len_str);
		chars_nb += print_prefix_and_pointer(result);
	}
	free(result);
	return (chars_nb);
}
