#include "ft_printf.h"
#include "libft/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
void ft_leftjustify (char *str, t_format format_info)
{
	size_t len;

	len = ft_strlen(str);
	//format_info.width = 10;
	ft_putstr(str);
	format_info.width -= len;
	while (format_info.width > 0)
	{
		ft_putchar(' ');
		format_info.width--;
	}
}

void ft_precision(char *str, t_format format_info)
{
	while (format_info.precision > 0 && *str)
	{
		ft_putchar(*str++);
		format_info.precision--;
	}
}

void ft_preci_lj(char *str, t_format format_info)
{
	while (format_info.precision > 0 && *str)
	{
		ft_putchar(*str++);
		format_info.precision--;
		format_info.width--;
	}
	while (format_info.width > 0)
	{
		ft_putchar(' ');
		format_info.width--;
	}
}

void ft_printstr(va_list args, t_format format_info)
{
	char *str;
	int len;
	int real_prec;
	int padding;

	str = va_arg(args, char *);
	len = ft_strlen(str);
	real_prec = (format_info.precision <= 0 || format_info.precision > len) ? len : format_info.precision;
	padding = (format_info.width > real_prec) ? (format_info.width - real_prec) : 0;
	if (!str)
	{
		ft_putstr("nil");
		return ;
	}
	if (format_info.left_justify)
	{
		write(1, str, real_prec);
		while(padding-- > 0)
			ft_putchar(' ');
	}
	else 
	{
		while (padding-- > 0)
			ft_putchar(' ');
		write(1, str, real_prec);
	}
}


	/*if (format_info.left_justify == 1 && format_info.precision == 0)
		ft_leftjustify(str, format_info);
	if (format_info.precision > 0 && format_info.left_justify == 0)
		ft_precision(str, format_info);
	if (format_info.precision > 0 && format_info.left_justify == 1)	
		ft_preci_lj(str, format_info);
	if (format_info.precision == 0 && format_info.left_justify == 0 && format_info.width > 0) 
	{
		format_info.width -= ft_strlen(str);
		while (format_info.width > 0)
		{
			ft_putchar(' ');
			format_info.width--;
		}
		ft_putstr(str);
	else if (format_info.precision > 0 && format_info.left_justify == 0 && format_info.width > 0)
	{
		format_info.width -= ft_strlen(str);
		ft_putstr(str);
		while (format_info.width > 0)
		{
			ft_putchar(' ');
			format_info.width--;
		}
	}
}
*/

void ft_printchar(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	ft_putchar(c);
}

void ft_printhexa_ptr(unsigned long long nb)
{
	char *hex_base;
	int i;
	char result[20];

	hex_base = "0123456789abcdef";
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	i = 0;
	while (nb > 0)
	{
		result[i++] = hex_base[nb % 16];
		nb = nb / 16;
	}
	result[i] = '\0';
	write(1, "0x", 2);
	while (i > 0)
	{
		i--;
		ft_putchar(result[i]);
	}
}

void ft_printpointer(va_list args, t_format format_info)
{
	void *ptr;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		ft_putstr("(nil)");
		return ;
	}
	ft_printhexa_ptr((unsigned long long) ptr);
}
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
		ft_putnbr_fd(nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + 48, fd);
}

void ft_printdecimal(va_list args)
{
	int result;

	result = va_arg(args, int);
	ft_putnbr_fd(result, 1);
}

void ft_put_udecimal(unsigned int nb, int fd)
{
	if (nb > 9)
	{
		ft_put_udecimal(nb / 10, fd);
		ft_put_udecimal(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + 48, fd);
}	

void ft_print_udecimal(va_list args)
{
	unsigned int result;

	result = va_arg(args, unsigned int);
	ft_put_udecimal(result, 1);
}

void ft_put_hexa(unsigned int nb, char c)
{
	char *hex_base;
	int i;
	char result[20];

	if (c == 'x')
		hex_base = "0123456789abcdef";
	else 
		hex_base = "0123456789ABCDEF";
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	i = 0;
	while (nb > 0)
	{
		result[i++] = hex_base[nb % 16];
		nb = nb / 16;
	}
	result[i] = '\0';
	while (i > 0)
	{
		i--;
		ft_putchar(result[i]);
	}
}

void ft_printhexa(va_list args, char c)
{
	unsigned int result;

	result = va_arg(args, unsigned int);
	ft_put_hexa(result, c);
}

void ft_specifier(const char **format, va_list args)
{
	t_format format_info;
	char c;
	format_info = parse_format(format);
	if (**format == 's')
		ft_printstr(args, format_info);
	else if (c == 'c')
		ft_printchar(args);
	else if (c == 'p')
		ft_printpointer(args, format_info);
	else if (c == 'd')
		ft_printdecimal(args);
	else if (c == 'i')
		ft_printdecimal(args);
	else if (c == 'u')
		ft_print_udecimal(args);
	else if (c == 'x' || c == 'X')
		ft_printhexa(args, c);
	else if (c == '%')
		ft_putchar('%');
}
