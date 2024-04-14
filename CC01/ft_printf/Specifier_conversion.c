#include "ft_printf.h"

int ft_printstr(va_list args, t_format format_info)
{
	char *str;
	int len;
	int real_prec;
	int padding;
	int result;

	str = va_arg(args, char *);
	if (!str && (format_info.precision == -1 || format_info.precision >= 6))
	{
		str = "(null)";
		format_info.precision = -1;
	}
	else if (!str)
	{
		str = "";
	}
	len = ft_strlen(str);
	real_prec = (format_info.precision < 0 || format_info.precision > len) ? len : format_info.precision;
	padding = (format_info.width > real_prec) ? (format_info.width - real_prec) : 0;
	result = 0;
	if (format_info.left_justify)
	{
		write(1, str, real_prec);
		result += real_prec;
		while(padding-- > 0)
			result += ft_putchar(' ');
	}
	else 
	{
		while (padding-- > 0)
			result += ft_putchar(' ');
		write(1, str, real_prec);
		result += real_prec;
	}
	return (result);
}

int ft_printchar(va_list args, t_format format_info)
{
	char c;
	int result;

	result = 0;
	c = (char)va_arg(args, int);
	if (format_info.left_justify == 1)
	{
		result += ft_putchar(c);
		while (format_info.width - 1 > 0)
		{
			result += ft_putchar(' ');
			format_info.width--;
		}
		return (result);
	}
	while (format_info.width - 1 > 0)
	{
		result += ft_putchar(' ');
		format_info.width--;
	}
	result += ft_putchar(c);
	return (result);
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
int ft_putstr_reverse(char *str)
{
	int len;
	int result;

	result = 0;
	len = ft_strlen(str);
	while (len - 1 >= 0)
	{
		result += ft_putchar(str[len - 1]);
		len--;
	}
	return (result);
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

int ft_nullpointer(t_format format_info)
{
	int result;

	result = 0;
	if (format_info.left_justify == 1)
	{
		result += ft_putstr_reverse(")lin(");
		while (format_info.width - 5 > 0)
		{
			result += ft_putchar(' ');
			format_info.width--;
		}
		return (result);
	}
	while (format_info.width - 5 > 0)
	{
		result += ft_putchar(' ');
		format_info.width--;
	}
	result += ft_putstr_reverse(")lin(");
	return (result);
}

int ft_printpointer(va_list args, t_format format_info)
{
	void *ptr;
	char *result;
	int len_str;
	int chars_nb;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		return(ft_nullpointer(format_info));
	}
	chars_nb = 0;
	result = ft_printhexa_ptr((unsigned long long) ptr);
	len_str = ft_strlen(result);
	if (format_info.left_justify == 1)
	{
		chars_nb += ft_putstr("0x");
		chars_nb += ft_putstr_reverse(result);
		while (format_info.width - 2 - len_str > 0)
		{
			chars_nb += ft_putchar(' ');
			format_info.width--;
		}
		free (result);
		return (chars_nb);
	}
	while (format_info.width - 2 - len_str > 0)
	{
		chars_nb += ft_putchar(' ');
		format_info.width--;
	}
	chars_nb += ft_putstr("0x");
	chars_nb += ft_putstr_reverse(result);
	free (result);
	return (chars_nb);
}

int ft_lennbr(int nbr, t_format format_info)
{
	int len;

	long nb;
	nb = nbr;
	len = 0;
	if (nb == 0 && format_info.precision == 0)
		return (0);
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

int ft_putnbr(int nb)
{
	int result;

	result = 0;
	if (nb > 9)
	{
		result += ft_putnbr(nb / 10);
	}
	result += ft_putchar(nb % 10 + 48);
	return (result);
}

int ft_printdecimal(va_list args, t_format format_info)
{
	int result;
	int is_negative;
	int num_len;
	int precision_padding;
	int sign_space;
	int total_padding;
	int chars_nb;

	chars_nb = 0;
	result = va_arg(args, int);
	is_negative = result < 0;
	num_len = ft_lennbr(is_negative ? -result : result, format_info);
	if (result == -2147483648)
		num_len = 10;
	precision_padding = (format_info.precision > num_len) ? format_info.precision - num_len : 0;
	sign_space = (is_negative || format_info.plus || format_info.space) ? 1 : 0;
	total_padding = format_info.width - (precision_padding + num_len + sign_space);

	if (!format_info.left_justify && (format_info.precision >= 0 || !format_info.zero_padding)) 
	{
		while (total_padding-- > 0) 
			chars_nb += ft_putchar(' ');
	}
	if (is_negative) 
		chars_nb += ft_putchar('-');
	else if (format_info.plus) 
		chars_nb += ft_putchar('+');
	else if (format_info.space) 
		chars_nb += ft_putchar(' ');
	if (!format_info.left_justify && format_info.zero_padding && format_info.precision < 0) 
	{
		while (total_padding-- > 0) 
			chars_nb += ft_putchar('0');
	}
	if ((result == 0 && format_info.precision != 0) || result != 0 )
	{
		while (precision_padding-- > 0) 
			chars_nb += ft_putchar('0');
		if (result == -2147483648)
			chars_nb += ft_putstr("2147483648");
		else
			chars_nb += ft_putnbr(is_negative ? -result : result);
	}
	if (format_info.left_justify) 
	{
		while (total_padding-- > 0) 
			chars_nb += ft_putchar(' ');
	}
	return (chars_nb);
}

int ft_put_udecimal(unsigned int nb, int fd)
{
	int result;

	result = 0;
	if (nb > 9)
	{
		result += ft_put_udecimal(nb / 10, fd);
	}
	result += ft_putchar((nb % 10) + 48);
	return (result);
}	

int ft_lenunbr_u(unsigned int result, t_format format_info)
{
	int len;

	len = 0;
	if (result == 0 && format_info.precision == 0)
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
int ft_print_udecimal(va_list args, t_format format_info)
{
	unsigned int result;
	int num_len;
	int precision_padding;
	int total_padding;
	int chars_nb;

	chars_nb = 0;
	result = va_arg(args, unsigned int);
	num_len = ft_lenunbr_u(result, format_info);
	precision_padding = (format_info.precision > num_len) ? format_info.precision - num_len : 0;
	total_padding = format_info.width - (precision_padding + num_len);
	if (!format_info.left_justify && (format_info.precision >= 0 || !format_info.zero_padding)) 
	{
		while (total_padding-- > 0) 
			chars_nb += ft_putchar(' ');
		total_padding = format_info.width - (precision_padding + num_len);
	}
	if (!format_info.left_justify && format_info.zero_padding && format_info.precision < 0) 
	{
		while (total_padding-- > 0) 
			chars_nb += ft_putchar('0');
		total_padding = format_info.width - (precision_padding + num_len);	
	}
	if (result != 0 || ( format_info.precision != 0 && result == 0))
	{
		while (precision_padding-- > 0) 
			chars_nb += ft_putchar('0');
		chars_nb += ft_put_udecimal(result, 1);
	}
	if (format_info.left_justify) 
	{
		while (total_padding-- > 0) 
			chars_nb += ft_putchar(' ');
	}
	return (chars_nb);
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

int ft_printhexa(va_list args, char c, t_format format_info)
{
	unsigned int result;
	char *return_value;
	int return_length;
	int prefix_length;
	int precision_padding;
	int chars_nb;

	chars_nb = 0;
	result = va_arg(args, unsigned int);
	return_value = ft_put_hexa(result, c);
	return_length = ft_strlen(return_value);
	prefix_length = (format_info.alternative_form && result != 0) ? 2 : 0; 
	precision_padding = (format_info.precision > return_length) ? format_info.precision - return_length : 0;
	format_info.width -= (return_length + precision_padding + prefix_length);
	if (result == 0 && format_info.precision == 0)
		format_info.width++;
	if (!format_info.left_justify) 
	{
		if (format_info.zero_padding && format_info.precision < 0) 
		{
			while (format_info.width > 0) 
			{
				chars_nb += ft_putchar('0');
				format_info.width--;
			}
		} 
		else 
		{
			while (format_info.width > 0) 
			{
				chars_nb += ft_putchar(' ');
				format_info.width--;
			}
		}
	}
	if (format_info.alternative_form && result != 0) 
	{
		chars_nb += ft_putchar('0');
		chars_nb += ft_putchar(c);
	}
	if (result != 0 || (result == 0 && format_info.precision != 0))
	{
		while (precision_padding-- > 0) 
			chars_nb += ft_putchar('0');
		chars_nb += ft_putstr_reverse(return_value); 
	}
	if (format_info.left_justify) 
	{
		while (format_info.width > 0) 
		{
			chars_nb += ft_putchar(' ');
			format_info.width--;
		}
	}
	free(return_value);
	return (chars_nb);
}

int ft_specifier(const char **format, va_list args)
{
	t_format format_info;
	int result;

	format_info = parse_format(format);
	if (**format == 's')
		result = ft_printstr(args, format_info);
	else if (**format == 'c')
		result = ft_printchar(args, format_info);
	else if (**format == 'p')
		result = ft_printpointer(args, format_info);
	else if (**format == 'd')
		result = ft_printdecimal(args, format_info);
	else if (**format == 'i')
		result = ft_printdecimal(args, format_info);
	else if (**format == 'u')
		result = ft_print_udecimal(args, format_info);
	else if (**format == 'x' || **format == 'X')
		result = ft_printhexa(args, **format, format_info);
	else if (**format == '%')
		result = ft_putchar('%');
	return (result);
}
