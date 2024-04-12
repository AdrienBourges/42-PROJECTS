#include "ft_printf.h"

int is_specifier(char c)
{
	if (c == 'c' || c =='s' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

t_format parse_format(const char **format)
{
	t_format format_info = {0};
	format_info.precision = -1;
	while (is_specifier(**format) == 0)
	{
		
		if (**format == '-')
			format_info.left_justify = 1;
		if (**format == '0' && format_info.left_justify == 0)
			format_info.zero_padding = 1;
		while (ft_isdigit(**format))
		{
			format_info.width = format_info.width * 10 + (**format - 48);
			(*format)++;
		}
		if (**format == '.')
		{
			format_info.precision = 0;
			(*format)++;
			while (ft_isdigit(**format))
			{
				
				format_info.precision = format_info.precision * 10 + (**format - 48);
				(*format)++;
			}
		}
		if (**format == '#')
			format_info.alternative_form = 1;
		if (**format == ' ')
			format_info.space = 1;
		if (**format == '+')
			format_info.plus = 1;
		if (is_specifier(**format) == 0)
			(*format)++;
	}
	return (format_info);	
}
/*
#include <stdio.h>

int main()
{
	t_format structest;
	const char *test = "+.3d";
	structest = parse_format(&test);
	printf("%d\n", structest.alternative_form);
	printf("%d\n", structest.zero_padding);
	printf("%d\n", structest.width);
	printf("%d\n", structest.space);
	printf("%d\n", structest.precision);
	printf("%d\n", structest.left_justify);
	printf("%d\n", structest.plus);


}
*/




