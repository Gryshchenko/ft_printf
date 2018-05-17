/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:46:44 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/26 13:52:43 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				pointer_arg_to_str_long(char **str, unsigned long c)
{
	if (c == 0)
		*str = ft_strdup("0");
	else
		*str = ft_itoa_base_16(c);
}

int					print_pointer_long(t_flags *flags, va_list ap)
{
	unsigned long	c_copy;
	unsigned long	c;
	char			*str;
	int				len;

	c = va_arg(ap, unsigned long);
	c_copy = c;
	flags->hash = 1;
	pointer_arg_to_str_long(&str, c);
	if (*str == '0' && flags->dot && !flags->precision)
	{
		ft_strdel(&str);
		str = ft_strnew(1);
	}
	print_precision(flags, &str);
	flag_hash_pointer(flags, &str);
	print_width(flags, &str);
	flag_minus(flags, &str);
	flag_null(flags, &str);
	check_null_end(flags, &str, c_copy);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int					print_pointer(va_list ap, t_flags *flags)
{
	int				len;

	len = print_pointer_long(flags, ap);
	return (len);
}
