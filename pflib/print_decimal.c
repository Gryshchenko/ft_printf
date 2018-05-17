/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:46:44 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 17:24:17 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					print_decimal_long(t_flags *flags, va_list ap)
{
	long long		c_copy;
	long long		c;
	char			*str;
	int				len;

	len = 0;
	c = va_arg(ap, long long);
	c_copy = c;
	if (c == 0)
		str = ft_strdup("0");
	else
		str = ft_itoa_long(c);
	print_precision(flags, &str);
	flag_plus(flags, &str, c);
	print_width(flags, &str);
	flag_minus(flags, &str);
	if (c_copy >= 0)
		flag_space(flags, &str);
	flag_null(flags, &str);
	check_null_end(flags, &str, c_copy);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int					print_decimal_int(t_flags *flags, va_list ap)
{
	int				c_copy;
	int				c;
	char			*str;
	int				len;

	len = 0;
	c = va_arg(ap, int);
	c_copy = c;
	if (c == 0)
		str = ft_strdup("0");
	else
		str = ft_itoa(c);
	print_precision(flags, &str);
	flag_plus(flags, &str, c);
	print_width(flags, &str);
	flag_minus(flags, &str);
	if (c_copy >= 0)
		flag_space(flags, &str);
	flag_null(flags, &str);
	check_null_end(flags, &str, c_copy);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int					print_decimal_signed(t_flags *flags, va_list ap)
{
	signed char		c_copy;
	signed char		c;
	char			*str;
	int				len;

	len = 0;
	c = va_arg(ap, int);
	c_copy = c;
	str = ft_itoa(c);
	print_precision(flags, &str);
	flag_plus(flags, &str, c);
	print_width(flags, &str);
	flag_minus(flags, &str);
	if (c_copy >= 0)
		flag_space(flags, &str);
	flag_null(flags, &str);
	check_null_end(flags, &str, c_copy);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int					print_decimal_short(t_flags *flags, va_list ap)
{
	short int		c_copy;
	short int		c;
	char			*str;
	int				len;

	len = 0;
	c = va_arg(ap, int);
	c_copy = c;
	if (c == 0)
		str = ft_strdup("0");
	else
		str = ft_itoa(c);
	print_precision(flags, &str);
	flag_plus(flags, &str, c);
	print_width(flags, &str);
	flag_minus(flags, &str);
	if (c_copy >= 0)
		flag_space(flags, &str);
	flag_null(flags, &str);
	check_null_end(flags, &str, c_copy);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int					print_decimal(va_list ap, t_flags *flags)
{
	int				len;

	len = 0;
	if (flags->type == 'D')
		len = print_decimal_long(flags, ap);
	else if (!flags->length)
		len = print_decimal_int(flags, ap);
	else if (flags->length == 3 || flags->length == 6 || flags->length == 4
		|| flags->length == 7)
		len = print_decimal_long(flags, ap);
	else if (flags->length == 2)
		len = print_decimal_signed(flags, ap);
	else if (flags->length == 1)
		len = print_decimal_short(flags, ap);
	return (len);
}
