/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 09:39:32 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 15:26:17 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				print_string_s(va_list ap, t_flags *flags)
{
	char		*str;
	char		*temp;
	int			len;

	temp = va_arg(ap, char *);
	if (temp == (void*)0)
		temp = "(null)";
	str = ft_strdup(temp);
	print_precision_string(flags, &str);
	print_width_string(flags, &str);
	flag_minus_string(flags, &str);
	flag_null(flags, &str);
	flag_plus_char(flags, &str);
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}

int				print_string_unicode(t_flags *flags, va_list ap)
{
	wchar_t		*str;
	size_t		len;
	char		*result;
	int			del;

	del = 0;
	str = va_arg(ap, wchar_t*);
	if (str == (void*)0)
	{
		result = ft_strnew(6);
		result = "(null)";
		del = 1;
	}
	else
		result = (char *)creat_wchar_string(flags, str);
	print_precision_string(flags, &result);
	print_width_string(flags, &result);
	flag_minus_string(flags, &result);
	flag_null(flags, &result);
	flag_plus_char(flags, &result);
	len = ft_strlen(result);
	ft_putstr(result);
	if (del != 1)
		free(result);
	return (len);
}

int				print_string(va_list ap, t_flags *flags)
{
	int			len;

	len = 0;
	if (flags->type == 's' && !flags->length)
		len = print_string_s(ap, flags);
	else if (flags->type == 'S' || (flags->length == 3 && flags->type == 's'))
		len = print_string_unicode(flags, ap);
	return (len);
}
