/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:26:22 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/31 13:37:24 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		selection_type(const char *s, int *i, va_list ap, t_flags *f)
{
	char		c;

	c = s[*i];
	f->type = s[*i];
	if (c == 'u' || c == 'U')
		return (print_unsigned(ap, f));
	if (c == 'i' || c == 'd' || c == 'D')
		return (print_decimal(ap, f));
	if (c == 's' || c == 'S')
		return (print_string(ap, f));
	if (c == 'p')
		return (print_pointer(ap, f));
	if (c == 'o' || c == 'O')
		return (print_octal(ap, f));
	if (c == 'x')
		return (print_hexadecimal(ap, f));
	if (c == 'X')
		return (print_hexadecimal_up(ap, f));
	if (c == 'c' || c == 'C')
		return (print_char(ap, f));
	else
		return (print_percent(f));
}

static int		check_type(const char *s, int *i)
{
	if (s[*i] == ' ' || s[*i] == '-' || s[*i] == '+' ||
			s[*i] == '.' || s[*i] == '0' || s[*i] == '#')
		return (0);
	if ((s[*i] == 'l' && s[*i + 1] == 'l') || (s[*i] == 'h' &&
		s[*i + 1] == 'h'))
		return (0);
	if ((s[*i] > 64 && s[*i] < 91) || (s[*i] > 96 && s[*i] < 123)
			|| s[*i] == '%')
		return (1);
	if ((s[*i] > 32 && s[*i] < 48) || (s[*i] > 57 && s[*i] < 65)
		|| (s[*i] > 90 && s[*i] < 97) || (s[*i] > 122 && s[*i] < 127))
		return (1);
	return (0);
}

void			clean_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->null = 0;
	flags->length = 0;
	flags->precision = 0;
	flags->width = 0;
	flags->length = 0;
	flags->dot = 0;
}

static int		parsing_string(const char *s, int *i, t_flags *f, va_list ap)
{
	clean_flags(f);
	while (s[*i])
	{
		selection_flags(s, i, f);
		selection_width(s, i, f);
		selection_precision(s, i, f);
		selection_lenght(s, i, f);
		selection_lenght_sec(s, i, f);
		if (check_type(s, i) == 1)
			break ;
	}
	return (selection_type(s, i, ap, f));
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*s;
	int			i;
	int			len;
	t_flags		flags;

	i = -1;
	len = 0;
	va_start(ap, format);
	s = (char *)format;
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (*s == '%' && ft_strlen(s) == 1)
				return (0);
			len += parsing_string(s, &i, &flags, ap);
		}
		else if (s[i] != '%' && (size_t)i <= ft_strlen(s))
			len += ft_putchar_printf(s[i]);
	}
	va_end(ap);
	return (len);
}
