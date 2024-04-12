#include "ft_printf.h"

void ft_printstr(va_list args, t_format format_info)
{
	char *str;
	int len;
	int real_prec;
	int padding;

	str = va_arg(args, char *);
	len = ft_strlen(str);
	real_prec = (format_info.precision < 0 || format_info.precision > len) ? len : format_info.precision;
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

void ft_printchar(va_list args, t_format format_info)
{
	char c;

	c = (char)va_arg(args, int);
	if (format_info.left_justify == 1)
	{
		ft_putchar(c);
		while (format_info.width - 1 > 0)
		{
			ft_putchar(' ');
			format_info.width--;
		}
		return ;
	}
	while (format_info.width - 1 > 0)
	{
		ft_putchar(' ');
		format_info.width--;
	}
	ft_putchar(c);
}

int ft_len_hexaptr(unsigned long long nb)
{
	int len;

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
void ft_putstr_reverse(char *str)
{
	int len;

	len = ft_strlen(str);
	while (len - 1 >= 0)
	{
		ft_putchar(str[len - 1]);
		len--;
	}
}

char *ft_printhexa_ptr(unsigned long long nb)
{
	char *hex_base;
	int i;
	char *result;

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

void ft_nullpointer(t_format format_info)
{
	if (format_info.left_justify == 1)
	{
		ft_putstr_reverse(")lin(");
		while (format_info.width - 5 > 0)
		{
			ft_putchar(' ');
			format_info.width--;
		}
		return ;
	}
	while (format_info.width - 5 > 0)
	{
		ft_putchar(' ');
		format_info.width--;
	}
	ft_putstr_reverse(")lin(");
}

void ft_printpointer(va_list args, t_format format_info)
{
	void *ptr;
	char *result;
	int len_str;

	ptr = va_arg(args, void *);	
	if (!ptr)
	{
		ft_nullpointer(format_info);
		return ;
	}
	result = ft_printhexa_ptr((unsigned long long) ptr);
	len_str = ft_strlen(result);
	if (format_info.left_justify == 1)
	{
		write (1, "0x", 2);
		ft_putstr_reverse(result);
		while (format_info.width - 2 - len_str > 0)
		{
			ft_putchar(' ');
			format_info.width--;
		}
		return ;
	}
	while (format_info.width - 2 - len_str > 0)
	{
		ft_putchar(' ');
		format_info.width--;
	}
	write(1, "0x", 2);
	ft_putstr_reverse(result);
	free (result);
}

int ft_lennbr(int nbr)
{
	int len;

	long nb;
	nb = nbr;
	len = 0;
	if (nb <= 0)
	{
		nb = -nb;
		len++;
	}	
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void ft_printdecimal(va_list args, t_format format_info)
{
	int result;
	int is_negative;
	int num_len;
	int precision_padding;
	int sign_space;
	int total_padding;

	result = va_arg(args, int);
	is_negative = result < 0;
	num_len = ft_lennbr(is_negative ? -result : result);
	precision_padding = (format_info.precision > num_len) ? format_info.precision - num_len : 0;
	sign_space = (is_negative || format_info.plus || format_info.space) ? 1 : 0;
	total_padding = format_info.width - (precision_padding + num_len + sign_space);

	if (!format_info.left_justify && (format_info.precision >= 0 || !format_info.zero_padding)) 
	{
		while (total_padding-- > 0) 
			ft_putchar(' ');
	}
	if (is_negative) 
		ft_putchar('-');
	else if (format_info.plus) 
		ft_putchar('+');
	else if (format_info.space) 
		ft_putchar(' ');
	if (!format_info.left_justify && format_info.zero_padding && format_info.precision < 0) 
	{
		while (total_padding-- > 0) 
			ft_putchar('0');
	}
	while (precision_padding-- > 0) 
		ft_putchar('0');
	ft_putnbr_fd(is_negative ? -result : result, 1);
	if (format_info.left_justify) 
	{
		while (total_padding-- > 0) 
			ft_putchar(' ');
	}
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

int ft_lenunbr(unsigned int result)
{
	int len;

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

void ft_print_udecimal(va_list args, t_format format_info)
{
	unsigned int result;
	int num_len;
	int precision_padding;
	int total_padding;

	result = va_arg(args, unsigned int);
	num_len = ft_lenunbr(result);
	precision_padding = (format_info.precision > num_len) ? format_info.precision - num_len : 0;
	total_padding = format_info.width - (precision_padding + num_len);
	if (!format_info.left_justify && (format_info.precision >= 0 || !format_info.zero_padding)) 
	{
		while (total_padding-- > 0) 
			ft_putchar(' ');
		total_padding = format_info.width - (precision_padding + num_len);
	}
	if (!format_info.left_justify && format_info.zero_padding && format_info.precision < 0) 
	{
		while (total_padding-- > 0) 
			ft_putchar('0');
		total_padding = format_info.width - (precision_padding + num_len);	
	}
	while (precision_padding-- > 0) 
		ft_putchar('0');
	ft_put_udecimal(result, 1);
	if (format_info.left_justify) 
	{
		while (total_padding-- > 0) 
			ft_putchar(' ');
	}
}

char *ft_put_hexa(unsigned int nb, char c)
{
	char *hex_base;
	int i;
	char *result;

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

void ft_printhexa(va_list args, char c, t_format format_info)
{
	unsigned int result;
	char *return_value;
	int return_length;
	int prefix_length;
	int precision_padding;

	result = va_arg(args, unsigned int);
	return_value = ft_put_hexa(result, c);
	return_length = ft_strlen(return_value);
	prefix_length = (format_info.alternative_form && result != 0) ? 2 : 0; 
	precision_padding = (format_info.precision > return_length) ? format_info.precision - return_length : 0;
	format_info.width -= (return_length + precision_padding + prefix_length);
	if (!format_info.left_justify) 
	{
		if (format_info.zero_padding && format_info.precision < 0) 
		{
			while (format_info.width > 0) 
			{
				ft_putchar('0');
				format_info.width--;
			}
		} 
		else 
		{
			while (format_info.width > 0) 
			{
				ft_putchar(' ');
				format_info.width--;
			}
		}
	}
	if (format_info.alternative_form && result != 0) 
	{
		ft_putchar('0');
		ft_putchar(c);
	}
	while (precision_padding-- > 0) 
		ft_putchar('0');
	ft_putstr_reverse(return_value); 
	if (format_info.left_justify) 
	{
		while (format_info.width > 0) 
		{
			ft_putchar(' ');
			format_info.width--;
		}
	}
	free(return_value);
}

void ft_specifier(const char **format, va_list args)
{
	t_format format_info;

	format_info = parse_format(format);
	if (**format == 's')
		ft_printstr(args, format_info);
	else if (**format == 'c')
		ft_printchar(args, format_info);
	else if (**format == 'p')
		ft_printpointer(args, format_info);
	else if (**format == 'd')
		ft_printdecimal(args, format_info);
	else if (**format == 'i')
		ft_printdecimal(args, format_info);
	else if (**format == 'u')
		ft_print_udecimal(args, format_info);
	else if (**format == 'x' || **format == 'X')
		ft_printhexa(args, **format, format_info);
	else if (**format == '%')
		ft_putchar('%');
}
