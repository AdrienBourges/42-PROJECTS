#include "ft_printf.h"

int	ft_len_hexaptr(unsigned long long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

int	ft_putstr_reverse(char *str)
{
	int	len;
	int	result;

	result = 0;
	len = ft_strlen(str);
	while (len - 1 >= 0)
	{
		result += ft_putchar(str[len - 1]);
		len--;
	}
	return (result);
}

int	ft_lenunbr(unsigned int result)
{
	int	len;

	len = 0;
	if (result == 0)
		return (1);
	while (result > 0)
	{
		result /= 10;
		len++;
	}
	return (len);
}

char	*ft_put_hexa(unsigned int nb, char c)
{
	char	*hex_base;
	int		i;
	char	*result;

	if (c == 'x')
		hex_base = "0123456789abcdef";
	else
		hex_base = "0123456789ABCDEF";
	i = 0;
	result = malloc (ft_lenunbr(nb) + 1);
	if (!result)
		return (NULL);
	if (nb == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	while (nb > 0)
	{
		result[i++] = hex_base[nb % 16];
		nb = nb / 16;
	}
	result[i] = '\0';
	return (result);
}

int	print_prefix2(int prefix_length, char c)
{
	if (prefix_length > 0)
	{
		ft_putchar('0');
		ft_putchar(c);
		return (2);
	}
	return (0);
}
