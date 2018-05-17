/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:31:10 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 14:08:45 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			print_char_c_null(t_flags *flags, char c)
{
	if (!c && !flags->width)
	{
		ft_putchar('\0');
		return (1);
	}
	return (0);
}

int			print_char_c(va_list ap, t_flags *flags)
{
	char	c;
	char	*str;
	int		len;

	len = 0;
	c = va_arg(ap, int);
	if (print_char_c_null(flags, c) == 1)
		return (1);
	str = ft_strnew(2);
	str[0] = c;
	if (!c && flags->width)
	{
		len++;
		print_width_char(flags, &str);
	}
	else
		print_width_char(flags, &str);
	flag_minus_char(flags, &str);
	ft_putstr(str);
	len += ft_strlen(str);
	ft_strdel(&str);
	if (c == 0)
		ft_putchar('\0');
	return (len);
}

void		print_width_unicode(t_flags *flags, char **str, int len)
{
	int		width;
	char	*newstr;
	char	*temp;
	int		i;

	i = -1;
	if ((size_t)flags->width)
	{
		width = flags->width - len;
		newstr = ft_strnew(width);
		if (flags->null && !flags->minus)
		{
			while (++i < width)
				newstr[i] = '0';
		}
		else
		{
			while (++i < width)
				newstr[i] = ' ';
		}
		temp = *str;
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}

int			print_char_unicode(va_list ap, t_flags *flags)
{
	wchar_t	c;
	char	*str;
	int		len;
	int		del;

	del = 0;
	str = (void*)0;
	c = va_arg(ap, unsigned int);
	len = ft_wcslen(c);
	if (flags->width)
	{
		str = ft_strnew(flags->width - len);
		print_width_unicode(flags, &str, len);
		len += ft_strlen(str);
		del = 1;
	}
	if (flags->minus)
		ft_putwchar(c);
	ft_putstr(str);
	if (!flags->minus)
		ft_putwchar(c);
	if (del)
		ft_strdel(&str);
	return (len);
}

int			print_char(va_list ap, t_flags *flags)
{
	int		len;

	len = 0;
	if (flags->type == 'c' && !flags->length)
		len = print_char_c(ap, flags);
	else if (flags->type == 'C' || (flags->length == 3 && flags->type == 'c'))
		len = print_char_unicode(ap, flags);
	return (len);
}
