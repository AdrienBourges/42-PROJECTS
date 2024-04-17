#include "ft_printf.h"

int	ft_lennbr(int nbr, t_format info)
{
	int		len;
	long	nb;

	nb = nbr;
	len = 0;
	if (nb == 0 && info.pre == 0)
		return (0);
	if (nb == 0)
	{
		len++;
	}
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	int		result;
	long	nbr;

	nbr = nb;
	result = 0;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr > 9)
		result += ft_putnbr(nbr / 10);
	result += ft_putchar(nbr % 10 + 48);
	return (result);
}

int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd')
		return (1);
	if (c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

t_format	init_format(void)
{
	t_format	f;

	f.left_justify = 0;
	f.zero_padding = 0;
	f.width = 0;
	f.pre = -1;
	f.alternative_form = 0;
	f.s = 0;
	f.p = 0;
	return (f);
}
