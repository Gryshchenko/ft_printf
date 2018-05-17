/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:46:44 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/26 18:37:09 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int						print_unsigned_long(t_flags *flags, va_list ap)
{
	unsigned long long	c_copy;
	unsigned long long	c;
	char				*str;
	int					len;

	c = va_arg(ap, unsigned long long);
	c_copy = c;
	str = ft_itoa_unsigned_long(c);
	print_precision(flags, &str);
	flag_plus(flags, &str, c);
	print_width(flags, &str);
	if (c_copy > 0 && flags->dot)
		flag_space(flags, &str);
	flag_minus(flags, &str);
	flag_null(flags, &str);
	check_null_end(flags, &str, c_copy);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int						print_unsigned_int(t_flags *flags, va_list ap)
{
	unsigned int		c_copy;
	unsigned int		c;
	char				*str;
	int					len;

	len = 0;
	c = va_arg(ap, int);
	c_copy = c;
	str = ft_itoa_unsigned(c);
	print_precision(flags, &str);
	flag_plus(flags, &str, c);
	print_width(flags, &str);
	flag_minus(flags, &str);
	if (c_copy > 0 && flags->dot)
		flag_space(flags, &str);
	flag_null(flags, &str);
	check_null_end(flags, &str, c_copy);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int						print_unsigned_unsigned(t_flags *flags, va_list ap)
{
	unsigned char		c_copy;
	unsigned char		c;
	char				*str;
	int					len;

	len = 0;
	c = va_arg(ap, int);
	c_copy = c;
	str = ft_itoa(c);
	print_precision(flags, &str);
	flag_plus(flags, &str, c);
	print_width(flags, &str);
	flag_minus(flags, &str);
	if (c_copy > 0)
		flag_space(flags, &str);
	flag_null(flags, &str);
	check_null_end(flags, &str, c_copy);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int						print_unsigned_short(t_flags *flags, va_list ap)
{
	unsigned short int	c_copy;
	unsigned short int	c;
	char				*str;
	int					len;

	len = 0;
	c = va_arg(ap, int);
	c_copy = c;
	str = ft_itoa(c);
	print_precision(flags, &str);
	flag_plus(flags, &str, c);
	print_width(flags, &str);
	flag_minus(flags, &str);
	if (c_copy > 0)
		flag_space(flags, &str);
	flag_null(flags, &str);
	check_null_end(flags, &str, c_copy);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int						print_unsigned(va_list ap, t_flags *flags)
{
	int					len;

	len = 0;
	if (!flags->length && flags->type != 'U')
		len = print_unsigned_int(flags, ap);
	else if (flags->type == 'U')
		len = print_unsigned_long(flags, ap);
	else if (flags->length == 3 || flags->length == 6 || flags->length == 4 ||
			flags->length == 7)
		len = print_unsigned_long(flags, ap);
	else if (flags->length == 2)
		len = print_unsigned_unsigned(flags, ap);
	else if (flags->length == 1)
		len = print_unsigned_short(flags, ap);
	return (len);
}
