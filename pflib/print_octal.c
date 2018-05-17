/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:27:51 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/26 13:47:11 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int						print_octal_long(t_flags *flags, va_list ap)
{
	unsigned long long	c_copy;
	unsigned long long	c;
	char				*str;
	int					len;

	c = va_arg(ap, unsigned long long);
	c_copy = c;
	if (c == 0)
		str = ft_strdup("0");
	else
		str = ft_itoa_base_8(c);
	flag_hash_octal(flags, &str);
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

int						print_octal_int(t_flags *flags, va_list ap)
{
	unsigned int		c_copy;
	unsigned int		c;
	char				*str;
	int					len;

	len = 0;
	c = va_arg(ap, int);
	c_copy = c;
	if (c == 0)
		str = ft_strdup("0");
	else
		str = ft_itoa_base_8(c);
	flag_hash_octal(flags, &str);
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

int						print_octal_unsigned(t_flags *flags, va_list ap)
{
	unsigned char		c_copy;
	unsigned char		c;
	char				*str;
	int					len;

	len = 0;
	c = va_arg(ap, int);
	c_copy = c;
	if (c == 0)
		str = ft_strdup("0");
	else
		str = ft_itoa_base_8(c);
	flag_hash_octal(flags, &str);
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

int						print_octal_short(t_flags *flags, va_list ap)
{
	unsigned short		c_copy;
	unsigned short		c;
	char				*str;
	int					len;

	len = 0;
	c = va_arg(ap, int);
	c_copy = c;
	if (c == 0)
		str = ft_strdup("0");
	else
		str = ft_itoa_base_8(c);
	flag_hash_octal(flags, &str);
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

int						print_octal(va_list ap, t_flags *flags)
{
	int					len;

	len = 0;
	if (!flags->length && flags->type != 'O')
		len = print_octal_int(flags, ap);
	else if (flags->type == 'O')
		len = print_octal_long(flags, ap);
	else if (flags->length == 3 || flags->length == 6 || flags->length == 4
			|| flags->length == 7)
		len = print_octal_long(flags, ap);
	else if (flags->length == 2)
		len = print_octal_unsigned(flags, ap);
	else if (flags->length == 1)
		len = print_octal_short(flags, ap);
	return (len);
}
