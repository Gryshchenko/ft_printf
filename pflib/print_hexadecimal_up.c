/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:42:30 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/26 13:35:00 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int						print_hexadecimal_up_signed(t_flags *flags, va_list ap)
{
	unsigned char		c_copy;
	unsigned char		c;
	char				*str;
	int					len;

	len = 0;
	c = va_arg(ap, unsigned int);
	hex_up_arg_to_str_signed(&str, c);
	c_copy = c;
	print_precision(flags, &str);
	flag_hash_hexadecimal_up(flags, &str, c);
	print_width(flags, &str);
	flag_minus(flags, &str);
	if (c_copy > 0)
		flag_space(flags, &str);
	flag_null(flags, &str);
	check_null_end(flags, &str, c_copy);
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}

int						print_hexadecimal_up_short(t_flags *flags, va_list ap)
{
	unsigned short int	c_copy;
	unsigned short int	c;
	char				*str;
	int					len;

	len = 0;
	c = va_arg(ap, unsigned int);
	hex_up_arg_to_str_short(&str, c);
	c_copy = c;
	print_precision(flags, &str);
	flag_hash_hexadecimal_up(flags, &str, c);
	print_width(flags, &str);
	flag_minus(flags, &str);
	if (c_copy > 0)
		flag_space(flags, &str);
	flag_null(flags, &str);
	check_null_end(flags, &str, c_copy);
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}

int						print_hexadecimal_up_long(t_flags *flags, va_list ap)
{
	long long			c_copy;
	long long			c;
	char				*str;
	int					len;

	len = 0;
	c = va_arg(ap, long long);
	hex_up_arg_to_str_long(&str, c);
	c_copy = c;
	print_precision(flags, &str);
	flag_hash_hexadecimal_up(flags, &str, c);
	print_width(flags, &str);
	flag_minus(flags, &str);
	if (c_copy > 0)
		flag_space(flags, &str);
	flag_null(flags, &str);
	check_null_end(flags, &str, c_copy);
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}

int						print_hexadecimal_up_int(t_flags *flags, va_list ap)
{
	unsigned int		c_copy;
	unsigned int		c;
	char				*str;
	int					len;

	len = 0;
	c = va_arg(ap, unsigned int);
	hex_up_arg_to_str_unsigned(&str, c);
	c_copy = c;
	print_precision(flags, &str);
	flag_hash_hexadecimal_up(flags, &str, c);
	print_width(flags, &str);
	flag_minus(flags, &str);
	if (c_copy > 0)
		flag_space(flags, &str);
	flag_null(flags, &str);
	check_null_end(flags, &str, c_copy);
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}

int						print_hexadecimal_up(va_list ap, t_flags *flags)
{
	int					len;

	len = 0;
	if (!flags->length)
		len = print_hexadecimal_up_int(flags, ap);
	if (flags->length == 3 || flags->length == 6 || flags->length == 4
			|| flags->length == 7)
		len = print_hexadecimal_up_long(flags, ap);
	if (flags->length == 2)
		len = print_hexadecimal_up_signed(flags, ap);
	if (flags->length == 1)
		len = print_hexadecimal_up_short(flags, ap);
	return (len);
}
