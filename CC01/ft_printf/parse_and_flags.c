#include "ft_printf.h"

void	parse_flags(const char **format, t_format *info)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
		{
			info->left_justify = 1;
			info->zero_padding = 0;
		}
		else if (**format == '0' && info->left_justify == 0)
		{
			info->zero_padding = 1;
		}
		(*format)++;
	}
}

void	parse_width(const char **format, t_format *info)
{
	while (ft_isdigit(**format))
	{
		info->width = info->width * 10 + (**format - '0');
		(*format)++;
	}
}

void	parse_precision(const char **format, t_format *info)
{
	if (**format == '.')
	{
		(*format)++;
		info->pre = 0;
		while (ft_isdigit(**format))
		{
			info->pre = info->pre * 10 + (**format - '0');
			(*format)++;
		}
	}
}

void	parse_additional_flags(const char **format, t_format *info)
{
	while (**format == '#' || **format == ' ' || **format == '+')
	{
		if (**format == '#')
		{
			info->alternative_form = 1;
		}
		else if (**format == ' ')
		{
			info->s = 1;
		}
		else if (**format == '+')
		{
			info->p = 1;
		}
		(*format)++;
	}
}

t_format	parse_format(const char **format)
{
	t_format	info ;

	info = init_format();
	info.pre = -1;
	while (is_specifier(**format) == 0)
	{
		parse_flags(format, &info);
		parse_width(format, &info);
		parse_precision(format, &info);
		parse_additional_flags(format, &info);
	}
	return (info);
}
